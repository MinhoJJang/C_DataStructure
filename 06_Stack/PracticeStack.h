#ifndef STACK_PRACTICE

#define STACK_PRACTICE

typedef int Data;

typedef struct _node {
	Data data;
	struct _node *pNext;
} Node;

typedef struct _stack {
	Node *pTop;
} Stack;


// ���� �ʱ�ȭ
void stack_init(Stack *pStack);

// ���� �����?
int stack_is_empty(Stack *pStack);
// ������� True, ������ False ���� 

// ���� ���� 
void stack_destroy(Stack *pStack);

// ������ �ֱ� 
int stack_push(Stack *pStack, Data data);

// ������ ���� 
int stack_pop(Stack *pStack, Data *pData);
// ���ÿ� �����Ͱ� ������ Fail

// ������ �̸�����  
int stack_peek(Stack *pStack, Data *pData);
// ���ÿ� �����Ͱ� ������ Fail

// ���� �Ϻ���! 


#endif
