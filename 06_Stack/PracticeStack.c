#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 
#include "PracticeStack.h"

#define SUCCESS 1
#define FAIL 0

// ���� �ʱ�ȭ
void stack_init(Stack *pStack) {
	pStack->pTop = NULL;
}

// ���� �����?
int stack_is_empty(Stack *pStack) {
	if (pStack->pTop != NULL) {
		return FAIL;
	}

	return SUCCESS;
}
// ������� SUCCESS, ������ FAIL ���� 

// ���� ���� 
//void stack_destroy(Stack *pStack) {
//	while (!stack_is_empty(pStack)) {
//		pStack->pTop = NULL;
//		// �̰� �����ϴ�. pTop���� �����Ȱ� �ϳ��̴ϱ�... �ٽ�!
//	}
//}

void stack_destroy(Stack *pStack)
{
	while (!stack_is_empty(pStack)) // ������ �� �����������
	{
		stack_pop(pStack, NULL); // ������ �� ����������� pop
	}
}


 //������ �ֱ� 

/*
int stack_push(Stack *pStack, Data data) {

	pStack->pTop->pNext = pStack->pTop;
	pStack->pTop->data = data;
	
} 1�� ���� 

int stack_push(Stack *pStack, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node)); 
	// malloc�Ҷ� ���� (Node*)���� *�� ����ü �ڿ� �־����.. 
	// �����޸� �Ҵ�. �� ��忡 ���� �޸𸮸� �Ҵ����ش�.

	memset(pNewNode, 0, sizeof(Node));
	// �� ��带 0���� �ʱ�ȭ�����ش�

	pNewNode->data = data;
	// �� ����� �����Ͱ��� ���� �����͸� �ִ´�. 
	//----------------������� ����-------------

	/*pStack->pTop->pNext = pNewNode;
	pNewNode = pStack->pTop;
	// ���� �ִ� pTop�� ���� ��尡 pNewNode�̰�, ������ pTop��ġ���� pNewNode�� ����. 
} 2�� ����. pStack->pTop�� ��ġ������ '��' �ؾ� ��
*/
int stack_push(Stack *pStack, Data data) {

	Node *pNewNode = (Node*)malloc(sizeof(Node));
	// malloc�Ҷ� ���� (Node*)���� *�� ����ü �ڿ� �־����.. 
	// �����޸� �Ҵ�. �� ��忡 ���� �޸𸮸� �Ҵ����ش�.

	memset(pNewNode, 0, sizeof(Node));
	// �� ��带 0���� �ʱ�ȭ�����ش�

	pNewNode->data = data;
	// �� ����� �����Ͱ��� ���� �����͸� �ִ´�. 

	// ���⼭ �� �����غ���, ���������� �����͸� ���ϱ� ���߿� ���°��� �ؿ� �ִ� ����� ��ġ�� �˾ƾ� �Ѵ�. ��...
	pNewNode->pNext = pStack->pTop;
	// �� ��尡 ����Ű�� ���� ���� �ٷ� �� ��尡 ������ ���� top�� ��ġ�ϴ� ����̴�. 

	// �׸��� pTop��ġ�� pNewNode�� �������ϱ�,
	pStack->pTop = pNewNode;
	
	return SUCCESS;
} // 3�� ����

// =========================

// ������ ���� 
// ���ÿ� �����Ͱ� ������ Fail

/*int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		return FAIL;
	}

	*pData = pStack->pTop->data;
	pStack->pTop = pStack->pTop->pNext;
	
	return SUCCESS;
} 1�� ����. �̷��� �ڵ带 �����, ���� ������ ���� ������� �ʰ� push�Ҷ� malloc�� �޸𸮸� �����Ѵ�. �����͸� �����µ� ������ ������ �޸����� ������ �����.  
*/

//1�� ���� �ǵ��: �� ���� �ִ� ��带 �ϴ� �ٸ� ��忡 ����ְ�, ��Ȳ ����Ǹ� free������.
int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS){
		printf("pop ����");
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
// �´����� Ȯ��ġ ����. �ڵ�� ���̰� ������..�غ����ҵ�
// 0718 ����) ��������. pop�Ҷ� *pData�� NULLptr�� ���� ������ ���� �߻���. �� *pData�� NULL�� �ƴҶ����� �����Ű���� ��������. 

int stack_pop(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		printf("pop ����");
		return FAIL;
	}

	Node *pCurrent = pStack->pTop;

	if (*pData != NULL) // *pData�� NULL�� �ƴҶ�����..

		*pData = pStack->pTop->data;
		pStack->pTop = pStack->pTop->pNext;

		free(pCurrent);

	return SUCCESS;
}


// ������ �̸�����  
// ���ÿ� �����Ͱ� ������ Fail
int stack_peek(Stack *pStack, Data *pData) {

	if (stack_is_empty(pStack) == SUCCESS) {
		printf("peek ����");
		return FAIL;
	}
	
	else { 
		*pData = pStack->pTop->data;

		return SUCCESS;
	}
}

