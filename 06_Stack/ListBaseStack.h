#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS 1
#define FAIL 0

/* ������ ADT */


/* ������ ������ */
typedef int Data; // �׳� int�� ������ ���ϴ°Ŷ� Data�� int �� �ٸ��ž���

typedef struct _node
{
	Data data;
	struct _node *pNext;

	// ����ü ���ο��� ����ü�� �ٽ� �ҷ��� �� ����. ����ü Ÿ�� ������ pNext�� ������.
} Node;

typedef struct _listStack
{
	Node *pTop; // �̹����������� numData ���� ����

} ListStack;

typedef ListStack Stack;

// {data�� ���� node�� �ּ�}�� ���� �ִ� (����ü Node Ÿ�� �� ������ pTop)�� ���� �ִ� [Stack�̶�� ����ü]�� ������. 


/* ������ ���� */

// ���� �ʱ�ȭ
void stack_init(Stack *pStack);

// ���� ���� 
void stack_destroy(Stack *pStack);

// ������ ������� Ȯ�� 
int stack_is_empty(Stack *pStack);

// push : top�� ������ �߰� 
int stack_push(Stack *pStack, Data data);

// pop : top�� ������ ������ 
int stack_pop(Stack *pStack, Data *pData);

// peek : top�� ������ �̸����� 
int stack_peek(Stack *pStack, Data *pData);

#endif // !__STACK_H__
