#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS 1
#define FAIL 0

/* 스택의 ADT */


/* 스택의 데이터 */
typedef int Data; // 그냥 int형 데이터 말하는거라서 Data나 int 나 다를거없음

typedef struct _node
{
	Data data;
	struct _node *pNext;

	// 구조체 내부에서 구조체를 다시 불러올 수 있음. 구조체 타입 포인터 pNext를 정의함.
} Node;

typedef struct _listStack
{
	Node *pTop; // 이번예제에서는 numData 유지 안함

} ListStack;

typedef ListStack Stack;

// {data와 다음 node의 주소}를 갖고 있는 (구조체 Node 타입 의 포인터 pTop)을 갖고 있는 [Stack이라는 구조체]를 만들음. 


/* 스택의 동작 */

// 스택 초기화
void stack_init(Stack *pStack);

// 스택 제거 
void stack_destroy(Stack *pStack);

// 스택이 비었는지 확인 
int stack_is_empty(Stack *pStack);

// push : top에 데이터 추가 
int stack_push(Stack *pStack, Data data);

// pop : top의 데이터 꺼내기 
int stack_pop(Stack *pStack, Data *pData);

// peek : top의 데이터 미리보기 
int stack_peek(Stack *pStack, Data *pData);

#endif // !__STACK_H__
