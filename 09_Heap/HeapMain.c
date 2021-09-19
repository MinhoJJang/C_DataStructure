#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#include "Heap.h"
#define HEAP_LEN 100

int DataPriorityComp(HData ch1, HData ch2) {
	// ch1이 더 크면 양수리턴, 작으면 음수, 같으면 0
	return ch2 - ch1; // min-heap

	// 왜  minheap는 안되지???
	// 해결 -> heap.c의 getHighPriority에서 오류가있었음

	// return ch1 - ch2; // max-heap
}

int main() {

	Heap heap;
	heap.heapArr[HEAP_LEN] = NULL;
	
	heap_init(&heap, DataPriorityComp);

	heap_insert(&heap, 9); // ph.heapArr[1] = 9
	// idx값은 0이 없으므로 0은 채워지지 않음
	heap_insert(&heap, 20);
	heap_insert(&heap, 30);
	//insert함과 동시에 DataPriorityComp 함수가 실행되어 우선순위를 비교해야한다. 

	// MIN-HEAP 
	//      (9)
	//     ↙  ↘
	//   (20)   (30)

	// MAX-HEAP 
	//      (30)
	//     ↙  ↘
	//   (9)    (20)

	//printf("%d \n", heap_delete(&heap)); // MAX-HEAP => 30, MIN-HEAP => 9
	//printf("%d \n", heap_delete(&heap)); // 20
	//printf("%d \n", heap_delete(&heap)); // 9
	//printf("%d \n", heap_delete(&heap));
	//printf("%d \n", heap_delete(&heap));

	
	
	// 도대체 나는 왜 heapArr[0]에 값이 들어가지?

	printf("\n");

	heap_insert(&heap, 15);
	heap_insert(&heap, 4);
	heap_insert(&heap, 8);
	heap_insert(&heap, 12);
	heap_insert(&heap, 13);
	heap_insert(&heap, 7);
	heap_insert(&heap, 1);
	heap_insert(&heap, 9);
	heap_insert(&heap, 3);
	heap_insert(&heap, 2);
	heap_insert(&heap, 10);
	heap_insert(&heap, 1);

	while (!heap_is_empty(&heap))
		printf("%d ", heap_delete(&heap));


	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
   _getch();
	return 0;
}