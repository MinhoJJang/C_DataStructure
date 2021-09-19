#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#include "PracticeStack.h"

#define SUCCESS 1
#define FAIL 0

// 스택 초기화
void stack_init(Stack *pStack) {
	pStack->pTop = NULL;
}

// 스택 비었나?
int stack_is_empty(Stack *pStack) {
	if (pStack->pTop != NULL) {
		return FAIL;
	}

	return SUCCESS;
}
// 비었으면 SUCCESS, 있으면 FAIL 리턴 

// 스택 제거 
//void stack_destroy(Stack *pStack) {
//	while (!stack_is_empty(pStack)) {
//		pStack->pTop = NULL;
//		// 이건 부족하다. pTop으로 지정된건 하나이니까... 다시!
//	}
//}

void stack_destroy(Stack *pStack)
{
	while (!stack_is_empty(pStack)) // 스택이 다 비어질때까지
	{
		stack_pop(pStack, NULL); // 스택이 다 비어질때까지 pop
	}
}


 //데이터 넣기 

/*
int stack_push(Stack *pStack, Data data) {

	pStack->pTop->pNext = pStack->pTop;
	pStack->pTop->data = data;
	
} 1차 실패 

int stack_push(Stack *pStack, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node)); 
	// malloc할때 앞의 (Node*)에서 *는 구조체 뒤에 있어야함.. 
	// 동적메모리 할당. 새 노드에 대한 메모리를 할당해준다.

	memset(pNewNode, 0, sizeof(Node));
	// 새 노드를 0으로 초기화시켜준다

	pNewNode->data = data;
	// 새 노드의 데이터값에 받은 데이터를 넣는다. 
	//----------------여기까지 맞음-------------

	/*pStack->pTop->pNext = pNewNode;
	pNewNode = pStack->pTop;
	// 원래 있던 pTop의 다음 노드가 pNewNode이고, 스택의 pTop위치에는 pNewNode가 들어간다. 
} 2차 실패. pStack->pTop의 위치변경을 '잘' 해야 함
*/
int stack_push(Stack *pStack, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node));
	// malloc할때 앞의 (Node*)에서 *는 구조체 뒤에 있어야함.. 
	// 동적메모리 할당. 새 노드에 대한 메모리를 할당해준다.

	memset(pNewNode, 0, sizeof(Node));
	// 새 노드를 0으로 초기화시켜준다

	pNewNode->data = data;
	// 새 노드의 데이터값에 받은 데이터를 넣는다. 

	// 여기서 잘 생각해보면, 위에서부터 데이터를 빼니까 나중에 들어온것이 밑에 있는 노드의 위치를 알아야 한다. 즉...
	pNewNode->pNext = pStack->pTop;
	// 새 노드가 가리키는 다음 노드는 바로 새 노드가 들어오기 전에 top에 위치하던 노드이다. 

	// 그리고 pTop위치에 pNewNode가 들어왔으니까,
	pStack->pTop = pNewNode;
	
	return SUCCESS;
} // 3차 성공

// =========================

// 데이터 빼기 
// 스택에 데이터가 없으면 Fail

/*int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		return FAIL;
	}

	*pData = pStack->pTop->data;
	pStack->pTop = pStack->pTop->pNext;
	
	return SUCCESS;
} 1차 실패. 이렇게 코드를 만들면, 스택 맨위의 노드는 사라지지 않고 push할때 malloc된 메모리를 차지한다. 데이터를 꺼내는데 문제는 없으나 메모리적인 문제가 생긴다.  
*/

//1차 실패 피드백: 맨 위에 있던 노드를 일단 다른 노드에 집어넣고, 상황 종료되면 free해주자.
int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS){
		printf("pop 실패");
		return FAIL;
	}

	else {
		Node *pCurrent = pStack->pTop;

		*pData = pStack->pTop->data;
		pStack->pTop = pStack->pTop->pNext;

		free(pCurrent);
		
		return SUCCESS;
	}
}
// 맞는지는 확실치 않음. 코드상 차이가 있으나..해봐야할듯
// 0718 수정) 문제있음. pop할때 *pData에 NULLptr이 들어가는 오류가 자주 발생함. 즉 *pData가 NULL이 아닐때에만 실행시키도록 만들어야함. 

int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		printf("pop 실패");
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;

	if (*pData != NULL) // *pData가 NULL이 아닐때에만..

		*pData = pStack->pTop->data;
		pStack->pTop = pStack->pTop->pNext;

		free(pCurrent);

	return SUCCESS;
}


// 데이터 미리보기  
// 스택에 데이터가 없으면 Fail
int stack_peek(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		printf("peek 실패");
		return FAIL;
	}
	
	else { 
		*pData = pStack->pTop->data;

		return SUCCESS;
	}
}

