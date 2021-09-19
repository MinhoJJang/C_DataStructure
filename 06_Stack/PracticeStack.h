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


// 스택 초기화
void stack_init(Stack *pStack);

// 스택 비었나?
int stack_is_empty(Stack *pStack);
// 비었으면 True, 있으면 False 리턴 

// 스택 제거 
void stack_destroy(Stack *pStack);

// 데이터 넣기 
int stack_push(Stack *pStack, Data data);

// 데이터 빼기 
int stack_pop(Stack *pStack, Data *pData);
// 스택에 데이터가 없으면 Fail

// 데이터 미리보기  
int stack_peek(Stack *pStack, Data *pData);
// 스택에 데이터가 없으면 Fail

// 좋아 완벽해! 


#endif
