#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 

/*
	free()
*	malloc(), 
*   calloc(), realloc()
*
*   memcpy(), memset()
*/

int main() {

	// 동적 메모리 할당: Dynamic memory allocation
	{
		int len = 100000; //백만 바이트의 메모리를 할당
		int *arr = (int*)malloc(len); 
		//(int*)로 강제형변환 하는 이유는??
		//memory-allocation
		//malloc(byte_size) 메모리블럭을 할당받고, 주소를 리턴
		//malloc은 void pointer 형식이므로 int* 로 바꿔준다.
		printf("arr[0] : %d\n", arr[0]);

		// 메모리 할당 받았으면 초기화 시켜주는것이 좋다. 
		// memset(주소, 초기화할 값, 바이트값)
		memset(arr, 0, len); // arr번지부터 len 만큼의 바이트를 0으로 초기화
		printf("arr[0] : %d\n", arr[0]);

		// 동적메모리는 사용한 후에 반드시 free (할당해제, 반납) 해야함 
		// 잠깐동안 빌린거니까..
		free(arr);

		// free(arr);  블럭안에서 사용하던 동적할당된 포인터는 잊어버리면 찾을수도없고 쓸수도없다.
		// 메모리는 한정된 공간인데 쓰지도않고 반납도 안하고 방치하면 메모리 낭비됨..
		// ★★ 메모리 누수 Memory Leak 발생 주의!!!! ★★
	}

	printf("\n"); 

	{
		//realloc() : re-allocation(). 메모리 재할당
		// 기존에 메모리 할당된 것들을 새로이 공간할당 받아서 내용복사
		// 동적 메모리에 사용된 배열 확장등에 좋다.

		int *arr1 = (int*)malloc(sizeof(int) * 3);
		//12byte
		arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
		//주의 
		arr1[3] = 40; // (내가 할당받은 메모리는 arr1[2] 까지인데 arr1[3] 넣어버리면 위험함)

		printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);

		// 동적메모리 재할당 (확장, 축소)
		//  기존의 arr1 에 할당된 공간은 해제 됩니다. (따로 free() 시키지 않아도 됨)
		// 새집으로 이사간당~
		arr1 = (int*)realloc(arr1, sizeof(int) * 5);

		arr1[3] = 40; //데이터값 추가로 넣기 

		printf("%d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3]);

		free(arr1);
	}	

	printf("\n메모리 프로파일링 시작 - 아무키나 누르면 시작합니다\n");
	//디버그-메모리 프로파일러-시작 
	_getch();
	{
		int len = 1000000;
		int *arr;

		// 메모리 누수 주의
		for (int i = 0; i < 10; i++) {
			arr = (int*)malloc(sizeof(int)*len); //'4백만 바이트' 를 '10번반복' 해서 다시 할당
			//이렇게 만들면 기존에있던 4백만 데이터가 전부 누수됨..
			//즉 free(arr);은 for문 내에 있어야함
			_sleep(5000); //delay ms 단위 1000ms = 1sec
			 //5초뒤에 free(arr)하고
			free(arr);
			_sleep(5000); //다시 5초뒤에 할당받고
		}
		//free(arr); // 메모리 누수 
		//메모리 프로파일러 돌려보면 계속 올라가다가 for문 종료시 한번 반납함. 결국 9번의 메모리는 반납할 길이 없음.. 그 메모리를 기억하는 포인터가 없기 때문에 
	}

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}