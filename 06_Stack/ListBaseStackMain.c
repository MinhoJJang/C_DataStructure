#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
//#include "ListBaseStack.h"
#include "PracticeStack.h"

int main() { //Data main 도 가능.. 

	Stack stack;
	Data data;

	stack_init(&stack); // 스택 생성 및 초기화

	// 데이터 push 
	// https://visualgo.net/en/list
	stack_push(&stack, 1); // 1
	stack_push(&stack, 2); // 2 - 1
	stack_push(&stack, 3); // 3 - 2 - 1
	stack_push(&stack, 4); // 4 - 3 - 2 - 1
	stack_push(&stack, 5); // 5 - 4 - 3 - 2 - 1

	//데이터 pop 
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data); // 5
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data); // 4

	while (!stack_is_empty(&stack)) { // 스택이 빌 때까지 // 3 , 2 , 1
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	for (int i = 100; i <= 500; i += 100) {
		stack_push(&stack, i);
	}

	stack_peek(&stack, &data);
	printf("peek->%d\n", data);

	while (!stack_is_empty(&stack)) {
		// 1000, 900, 800, ... , 100
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	stack_peek(&stack, &data);
	printf("peek->%d\n", data);

	stack_pop(&stack, &data);
	printf("pop--> %d\n", data);

	stack_destroy(&stack); // 스택제거 

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}