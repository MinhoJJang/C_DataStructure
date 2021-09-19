#ifndef __QUEUE__
#define __QUEUE__

#define SUCCESS	1
#define FAIL	0

typedef int Data; 

typedef struct _node
{
	Data data;
	struct _node *pNext;
	
} Node;

typedef struct _queue {
	Node *pFront;
	Node *pBack;
	int numdata;
} Queue;

// 큐의 동작

// 1. 큐 초기화 
void queue_init(Queue *pq);

// 2. 큐 파괴 
void queue_destroy(Queue *pq);

// 3. 큐에 자료가 비어있는가?
int queue_is_empty(Queue *pq);

// 4. 큐에 자료 넣기 
int queue_enq(Queue *pq, Data data);

// 5. 큐에서 자료뺴기 
int queue_deq(Queue *pq, Data *pData);

// 6. 큐에서 자료 미리보기
int queue_peek(Queue *pq, Data *pData);


#endif