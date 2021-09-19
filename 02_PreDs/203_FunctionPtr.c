#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 

/*
	함수 포인터 (function pointer)
	'함수이름' 이 곧 '포인터' 
*/

void fnPlus(int a, int b) {
	printf("덧셈: %d + %d = %d\n", a, b, a + b);
}

void fnMinus(int a, int b)
{
	printf("빼기: %d - %d = %d\n", a, b, a - b);
}

void fnMul(int a, int b)
{
	printf("곱셈: %d * %d = %d\n", a, b, a * b);
}

void fnDiv(int a, int b)
{
	printf("나눗셈: %d / %d = %d\n", a, b, a / b);
}

void doAction(int a, int b, void(*fnOp)(int, int)) {
	//함수 안의 함수
	(*fnOp)(a, b);
}

//void(*fnOp)(int, int) => fnAction(int, int)로 만들어서 쓰는 경우가 많음
typedef void fnAction(int, int); //fnAction은 함수이름이 아니라 '함수포인터 타입' 이다! 개어렵네!!!ㅠㅠ

void doAction2(int a, int b, fnAction *fnOp) {
	(*fnOp)(a, b);
}

int main() {

	{
		fnPlus(10, 20);

		printf("fnPlus -> %p\n", fnPlus);
		//함수이름은 곧 함수포인터

		//함수포인터의 '참조' 는 곧 '호출' 동작이다.
		// 참조연산자 * 사용해서 호출 가능 

		(*fnPlus)(30, 40); //호출

		// 함수 포인터 타입 변수 선언 가능
		// int *p;   <-- int 에 대한 포인터
		// void 리턴하고 (int, int) 매개변수 받는 함수에 대한 함수 포인터?
		void(*fnOp)(int, int); // <-- fnOp 라는 '함수 포인터 변수 선언'

		// 포인터변수 <- 대입 가능 
		// 함수를 대입할수 있다!!
		fnOp = (*fnPlus); 
		//(*fnPlus)=fnPlus
		//이제 fnOp는 함수처럼 사용 가능
		(*fnOp)(70, 100);

		printf("\n");
		{
			// 함수포인터의 이점.
			// '동작'을 나중에 연결 가능 (late-binding)

			int op;
			printf("동작번호를 입력하세요(0:+ 1:- 2:* 3:/): ");
			scanf("%d", &op);

			int a = 30, b = 10;
			int i = 0;
			for (i = 0; i < 5; i++)
			{
				if (op == 0)
					fnPlus(a, b);     //< --이 라인의 실행코드는 100 % fnPlus 를 호출한다!
				else if (op == 1)
					fnMinus(a, b);    //< --이 라인의 실행코드는 100 % fnMinus 다!
				else if (op == 2)
					fnMul(a, b);      //
				else if (op == 3)
					fnDiv(a, b);
			}

			// ↑ 이미 컴파일할때 코드상에 명시된 '특정'함수가 실행되도록 바인딩 된다.  --> Early Binding 이라 함
			// 매 순환문마다 조건문을 통해 고정된 함수 호출을 호출해야 하니, 조건문기본 로드가 큼
			// 매번 반복하는건 시간초과의 위험이 큼.

			// 반면
			// 함수포인터 선언 
			void(*fnAction)(int, int);

			// 함수포인터 배열
			void(*fnOpArr[])(int, int) = {fnPlus, fnMinus, fnMul, fnDiv};

			fnAction = fnOpArr[op]; //op: 0~3

			printf("\n");
			for (i = 0; i < 5; i++) {
				(*fnAction)(a, b);

				// 걍 fnAction 을 수행.. 그런데 컴파일 점에선 무엇을 실행한진 모른다 (즉 바인딩이 되어 있지 않다)
				// 실행 해야 나중에 동작이 결정된다.   late-binding

				// 장점: 조건문에 의한 로드가 적다.
				// 성능향상!!
			}
		}

		// 함수 포인터도 포인터다!  
		// 매개변수로 넘겨줄수도, 리턴값으로 받을수도
		// 배열 원소가 될수도 있다!!

		printf("\n");
		{
			doAction(333, 444, fnPlus);
			doAction(333, 444, fnMinus);
			doAction2(333, 444, fnMul);
			doAction2(333, 444, fnDiv);
		}
	}

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}