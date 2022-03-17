#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
//#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>				// clock .. 시간 날짜 함수
#pragma warning(disable : 4996) // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable : 4477) // unsigned <--> signed 관련 warning

#define SUCCESS 1
#define FAIL 0

#define YES 1
#define NO 0

//#include "Queue1.h"
#include "Prac_Queue.h"

int main()
{
	// Queue 생성 및 초기화
	Queue q;
	Data data;
	queue_init(&q);

	// enqueue
	queue_enq(&q, 1); // front <-- [1] <-- back
	queue_enq(&q, 2); // front <-- [1 2] <-- back
	queue_enq(&q, 3); // front <-- [1 2 3] <-- back
	queue_enq(&q, 4); // front <-- [1 2 3 4] <-- back
	queue_enq(&q, 5); // front <-- [1 2 3 4 5] <-- back

	queue_deq(&q, &data);
	printf("deq --> %d\n", data); // 1
	queue_deq(&q, &data);
	printf("deq --> %d\n", data); // 2

	while (queue_is_empty(&q) != YES)
	// queue_is_empty(&q) != YES 은
	// !queue_is_empty(&q) 와 같은 의미이다.
	{
		queue_deq(&q, &data);
		printf("%d ", data); // 3 4 5
	}
	printf("\n");

	queue_destroy(&q); // 큐 제거

	printf("\n아무키나 입력하면 프로그램 종료됩니다\n");
	_getch();
	return 0;
}
