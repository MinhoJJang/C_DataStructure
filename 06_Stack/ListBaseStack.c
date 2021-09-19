#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#include "ListBaseStack.h"

#define SUCCESS 1
#define FAIL 0


// 스택 초기화
void stack_init(Stack *pStack) {
	pStack->pTop = NULL;
}


// 스택 제거 
void stack_destroy(Stack *pStack) 
{
	while (!stack_is_empty(pStack)) // 스택이 다 비어질때까지
	{
		stack_pop(pStack, NULL); // 스택이 다 비어질때까지 pop
	}
}

// 스택이 비었는지 확인 
int stack_is_empty(Stack *pStack) {
	if (pStack->pTop == NULL) return SUCCESS;

	return FAIL;
}

// push : top에 데이터 추가 
int stack_push(Stack *pStack, Data data) {
	// 새로운 노드 생성 
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->data = data;
	
	// 노드를 스택에 추가 (리스트 맨 앞에 insert)
	pNewNode->pNext = pStack->pTop;
	pStack->pTop = pNewNode;
	

	return SUCCESS;
}


// pop : top의 데이터 꺼내기 
int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack)) {
		printf("Empty Stack\n");
		return FAIL;
	}

	Node *pCurrent = pStack->pTop; // 삭제할 노드 기억

	if (pData != NULL)
		*pData = pStack->pTop->data; //데이터 읽기(꺼내기)

	pStack->pTop = pStack->pTop->pNext; // top 이동

	free(pCurrent); // pop 된 노드 제거 

	return SUCCESS;
}


// peek : top의 데이터 미리보기 
int stack_peek(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack)) {
		printf("Empty Stack\n");
		return FAIL;
	}

	if (pData != NULL)
		*pData = pStack->pTop->data; //데이터 읽기(꺼내기)

	return SUCCESS;
}