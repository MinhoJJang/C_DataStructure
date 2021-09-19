#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 

typedef void fnAction(int); // 측정할 함수 타입

void chkTime(char *szTitle, fnAction action, int datasize) {

	clock_t start, end;
	long result;

	printf("%s : size[%d] 측정시작\n", szTitle, datasize);
	start = clock(); // 시간 측정 시작 

	action(datasize);

	end = clock(); 
	result = end - start;
	printf("%s : size[%d] 경과시간 %ld ms\n", szTitle, datasize, result);
}


void func1(int size) {

	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum++;
		// size값에 비례해서 걸린 시간도 증가
	}
}

void func2(int size) {

	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			sum++;
			// size^2에 비례해서 걸린 시간이 증가 
		}
	}
}

void func3(int size) {

	int sum = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				sum++;
				// size^3에 비례해서 걸린 시간이 증가 
			}
		}
	}
}


int main() {

	int size;
	{
		size =10000000;
		chkTime("O(n)", func1, size);
		chkTime("O(n)", func1, size*2); // *시간 2배 증가 
		chkTime("O(n)", func1, size*4); // *2배 
	}

	{
		size = 5000;
		chkTime("O(n^2)", func2, size);
		chkTime("O(n^2)", func2, size * 2); // *4배 
		chkTime("O(n^2)", func2, size * 4); // *4배 
	}

	{
		size = 500;
		chkTime("O(n^3)", func3, size);
		chkTime("O(n^3)", func3, size * 2); // *8배 
		chkTime("O(n^3)", func3, size * 4); // *8배
	}
	

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}