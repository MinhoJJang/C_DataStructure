#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 
#include "Prac_Queue.h"

#define SUCCESS	1
#define FAIL	0

#define YES 1
#define NO 0

// 1. ť �ʱ�ȭ 
void queue_init(Queue *pq) {
	pq->pBack = NULL;
	pq->pFront = NULL;
	pq->numdata = 0;
}

// 2. ť�� �ڷᰡ ����ִ°�?
int queue_is_empty(Queue *pq) {
	if (pq->pFront == NULL) {
		return YES;
	}
	return NO;
}

// 3. ť�� �ڷ� �ֱ� 
int queue_enq(Queue *pq, Data data) {

	// (1) �ϴ� �����͸� ������� ��带 ������. 
	Node *pNewNode = (Node*)malloc(sizeof(Node)); // �����͸� malloc�� �޸� �Ҵ��ϴ°�..

	// (2) �� ��忡 �����͸� �־��ش�. 
	pNewNode->data = data;
	pNewNode->pNext = NULL; // ��ģ�� 1) pNewNode�� �ʱ�ȭ���Ѿ��ϴϱ� NULL�� �ʱ�ȭ�����ش�. 
	
	// (3) ���� ť�� �ڷᰡ ���� ���, pBack, pFront�� ���ÿ� pNewNode�� ����Ű�� �����. 
	if (queue_is_empty(pq) == YES) {
		pq->pBack = pNewNode;
		pq->pFront = pNewNode;
	}

	// (4) ť�� 1�� �̻� �����Ͱ� �ִ� ���, ���� ���� ���� pBack�� ��ġ�ϰ�, pFront�� �״�� �����Ѵ�. 
	else {
		pq->pBack->pNext = pNewNode; // ��ģ�� 2) front�� �״�� �����Ƿ��� ��ǻ� ���������� �ȵ�. ���� back�� �ִ� ����� ���� ��尡 ���ο� back�� ��ġ�ϴ� ���̹Ƿ� stack�� ����ϰ� back�� ����������. 
		pq->pBack = pNewNode;		
	}
	pq->numdata++;

	return SUCCESS;
}

// 4. ť���� �ڷ���� 
int queue_deq(Queue *pq, Data *pData) {

	// �ϴ� ���� �ڷᰡ �ִ������� ���캻��. 
	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	// ��ģ�� 3) pData�� NULL�� �Ǹ� �ȵǴϱ�..
	if (pData != NULL) 
		// (1) front data�� *pData�� ����.
		*pData = pq->pFront->data;

	// (2) ���� front��带 ���� ���ο� ��带 ����������. 
	Node *pCurNode = (Node*)malloc(sizeof(Node));

	// (3) front Node �� pCurNode �� �ű��
	pCurNode = pq->pFront;

	// (4) front��ġ�� �������ְ�
	pq->pFront = pq->pFront->pNext;

	// (5) pCurNode�� free���ְ� numdata-- ���ش�.
	free(pCurNode);
	pq->numdata--;
	
	return SUCCESS;
} // ���� �ٸ�. Ȯ���غ����ҵ�. 

// 5. ť���� �ڷ� �̸�����
int queue_peek(Queue *pq, Data *pData) {
	
	if (queue_is_empty(pq) == YES) {
		return FAIL;
	}

	if(pData != NULL)
		*pData = pq->pFront->data;

	return SUCCESS;
}

// 6. ť ������  
void queue_destroy(Queue *pq) {
	while (!queue_is_empty(pq)) {
		queue_deq(pq, NULL);
	}
}
