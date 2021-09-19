#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 


/*
	구조체 (struct)
		여러개의 데이터들 (멤버) 로 구성된 사용자 정의 자료형


	학생의 데이터
		-학번 : char[]
		-이름 : char[]
		-나이 : unsigned char  (0 ~ 255)
		-학년 : unsigned char
		-성별 : 'M', 'F'  char
		-키 : 173.4  float
		...
*/

struct point {
	int x; //멤버 변수
	int y; //멤버 변수 
	//point라는 구조체를 구성하고있는 멤버 변수 int 타입 x,y
}; //구조체 정의

struct person
{
	char name[20]; // 이름
	int age;				// 나이
	double weight;	// 몸무게
};

typedef struct person PS; //struct person = PS


typedef struct _person {
	char name[20]; // 이름
	int age;				// 나이
	double weight;	// 몸무게
} Person; 
//struct _person 이라는 구조체를 앞으로 Person이라고 부르겠다는 의미
// 30~37번 라인을 합친것. 


int main() {

	struct point p1;



	// 멤버연산자 ( . ) 사용해서 구조체 멤버 사용.
	p1.x = 100; //(p1의 x에는 100을 대입한다)
	p1.y = 200;

	printf("p1 => (%d,%d)\n", p1.x, p1.y);

	struct person p2; 
	// = PS p2; 

	p2.age = 32;
	p2.weight = 74.3;
	strcpy(p2.name, "홍길동");
	//p2.name같은곳에 직접 문자열을 대입할수 없으니까 string copy 사용해서 대입

	printf("이름 : %s , 나이 : %d살 , 몸무게 : %.1fkg\n", p2.name, p2.age, p2.weight);

	PS p3;
	Person p4;
	Person p5 = { "LOKI", 100, 87.567 }; 
	//선언과 동시에 초기화 가능 
	printf("이름 : %s , 나이 : %d살 , 몸무게 : %.1fkg\n", p5.name, p5.age, p5.weight);

	// 구조체에 대한 포인터

	Person *ptr = &p5;

	printf("이름 : %s , 나이 : %d살 , 몸무게 : %.1fkg\n", ptr->name, ptr->age, ptr->weight); 
	//or
	printf("이름 : %s , 나이 : %d살 , 몸무게 : %.1fkg\n", (*ptr).name, (*ptr).age, (*ptr).weight);

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}

//문제구상

// 입력할 학생수를 입력하고, 학생수만큼의 학생의 정보를 담는 구조체를 만들고 데이터를 받은 다음 x를 입력받아서 x번째 학생의 정보를 리턴하게 하려면...?