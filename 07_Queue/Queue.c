#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi .. 동적메모리, 난수, 문자열 변환
#include <string.h> // strcpy .. 문자열 함수.  memcpy.. 메모리블럭 함수
#include <conio.h>  // _getch, putch .. MS 기반 C비표준 함수
#include <time.h>   // clock .. 시간 날짜 함수
#pragma warning(disable:4996)  // scanf() 등 전통 C함수중 버퍼문제.
#pragma warning(disable:4477)  // unsigned <--> signed 관련 warning

#include "Queue1.h"

#define SUCCESS	1
#define FAIL	0

// 큐 초기화
void queue_init(Queue *pq)
{
	pq->pFront = NULL;
	pq->pBack = NULL;
}

// 큐 제거
void queue_destroy(Queue *pq)
{
	// 큐가 다 비어질때까지 dequeue
	while (queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}
 

// 큐가 비어있는지?
int queue_is_empty(Queue *pq)
{
	if (pq->pFront == NULL) return SUCCESS;

	return FAIL;
}

// enqueue, 데이터 추가 (back 에 추가)
int queue_enq(Queue *pq, Data data)
{
	// 새로운 노드 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	pNewNode->pNext = NULL;
	pNewNode->data = data;

	// 큐가 비어있을때와 그렇지 않을때 구분
	if (queue_is_empty(pq))
	{
		pq->pFront = pNewNode;
		pq->pBack = pNewNode;
		// 비어있을 경우 front 와 back 가 같은 값을 가리킴
	}
	else
	{
		pq->pBack->pNext = pNewNode;
		pq->pBack = pNewNode;
		// back가 가장 나중의 데이터이므로 나중의 데이터의 뒤에 새로운 노드를 집어넣고, back를 새로운 노드로 지정
	}

	return SUCCESS;

	// ※ LinkedList.c 의 list_add() 함수와 비교해보자
	//    dummy node 를 사용한것(LinkedList)와
	//    그렇지 않은것(Queue)도 비교
	//   dummy node  를 사용하면 코드가 더욱 간결해진다. (분기가 적어진다)
}

// dequeue, 데이터 꺼내기 (front 에서 추출)
int queue_deq(Queue *pq, Data *pData)
// dequeue의 경우 맨 처음 들어온 값, 즉 front가 제일 먼저 나간다. 
{
	// 1. 데이터가 큐에 없을 경우
	if (!queue_is_empty(pq)) {
		printf("Queue EMPTY!\n");
		return FAIL;
	}

	// 2. 데이터가 큐에 있을 경우 
	if (pData != NULL) // 포인터 pData에 값이 있으면 
		*pData = pq->pFront->data;   // front 의 데이터 추출

	Node *deleteNode = pq->pFront;   // 삭제할 노드 기억 queue의 front에 있는 값을 node형 포인터 deleteNode로 지칭
	pq->pFront = pq->pFront->pNext;   // front 는 다음 노드로 이동

	free(deleteNode);

	return SUCCESS;
}

// peek, 데이터 들여다 보기 (front)
int queue_peek(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq)) {
		printf("Queue EMPTY!\n");
		return FAIL;
	}

	if (pData != NULL)
		*pData = pq->pFront->data;   // front 의 데이터 추출

	return SUCCESS;
}