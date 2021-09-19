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

// ť�� ����

// 1. ť �ʱ�ȭ 
void queue_init(Queue *pq);

// 2. ť �ı� 
void queue_destroy(Queue *pq);

// 3. ť�� �ڷᰡ ����ִ°�?
int queue_is_empty(Queue *pq);

// 4. ť�� �ڷ� �ֱ� 
int queue_enq(Queue *pq, Data data);

// 5. ť���� �ڷ���� 
int queue_deq(Queue *pq, Data *pData);

// 6. ť���� �ڷ� �̸�����
int queue_peek(Queue *pq, Data *pData);


#endif