#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#include "Prac_Queue.h"

#define SUCCESS	1
#define FAIL	0

#define YES 1
#define NO 0

// 1. 큐 초기화 
void queue_init(Queue *pq) {
	pq->pBack = NULL;
	pq->pFront = NULL;
	pq->numdata = 0;
}

// 2. 큐에 자료가 비어있는가?
int queue_is_empty(Queue *pq) {
	if (pq->pFront == NULL) {
		return YES;
	}
	return NO;
}

// 3. 큐에 자료 넣기 
int queue_enq(Queue *pq, Data data) {

	// (1) 일단 데이터를 집어넣을 노드를 만들자. 
	Node *pNewNode = (Node*)malloc(sizeof(Node)); // 포인터를 malloc로 메모리 할당하는것..

	// (2) 새 노드에 데이터를 넣어준다. 
	pNewNode->data = data;
	pNewNode->pNext = NULL; // 놓친점 1) pNewNode를 초기화시켜야하니까 NULL로 초기화시켜준다. 
	
	// (3) 만약 큐에 자료가 없을 경우, pBack, pFront가 동시에 pNewNode를 가리키게 만든다. 
	if (queue_is_empty(pq) == YES) {
		pq->pBack = pNewNode;
		pq->pFront = pNewNode;
	}

	// (4) 큐에 1개 이상 데이터가 있는 경우, 새로 만든 노드는 pBack에 위치하고, pFront는 그대로 유지한다. 
	else {
		pq->pBack->pNext = pNewNode; // 놓친점 2) front가 그대로 유지되려면 사실상 움직여서는 안됨. 원래 back에 있던 노드의 다음 노드가 새로운 back에 위치하는 것이므로 stack과 비슷하게 back를 움직여주자. 
		pq->pBack = pNewNode;		
	}
	pq->numdata++;

	return SUCCESS;
}

// 4. 큐에서 자료뺴기 
int queue_deq(Queue *pq, Data *pData) {

	// 일단 먼저 자료가 있는지부터 살펴본다. 
	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	// 놓친점 3) pData가 NULL이 되면 안되니까..
	if (pData != NULL) 
		// (1) front data를 *pData에 담자.
		*pData = pq->pFront->data;

	// (2) 현재 front노드를 담을 새로운 노드를 지정해주자. 
	Node *pCurNode = (Node*)malloc(sizeof(Node));

	// (3) front Node 를 pCurNode 로 옮기고
	pCurNode = pq->pFront;

	// (4) front위치를 변경해주고
	pq->pFront = pq->pFront->pNext;

	// (5) pCurNode를 free해주고 numdata-- 해준다.
	free(pCurNode);
	pq->numdata--;
	
	return SUCCESS;
} // 조금 다름. 확인해봐야할듯. 

// 5. 큐에서 자료 미리보기
int queue_peek(Queue *pq, Data *pData) {
	
	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	if(pData != NULL)
		*pData = pq->pFront->data;

	return SUCCESS;
}

// 6. 큐 버리기  
void queue_destroy(Queue *pq) {
	while (!queue_is_empty(pq)) {
		queue_deq(pq, NULL);
	}
}
