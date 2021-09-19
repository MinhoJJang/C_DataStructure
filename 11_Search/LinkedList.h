#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

/*
*	LinkedList �� ADT
*
*	����: ����, ���� ����
*	����: ��ȸ�� �Ҹ�
*
*	����: ArrayList�� ���� �뷮 UP
*/

/* List �� ������ */
typedef int Data;

// ��� Ÿ�� ����
typedef struct _node 
{
	Data data; // ��� ������
	struct _node *pNext; // ���� ��� ������ 
} Node;

// Linked List Ÿ�� ����
typedef struct _linkedList 
{
	Node *pHead;
	Node *pTail;

	Node *pCurrent; //iteration �� 
	int numData;
} LinkedList;

typedef LinkedList List;

/* List �� ���� */
// ����Ʈ �ʱ�ȭ
void list_init(List *pList);

// ����Ʈ ���� 
void list_destroy(List *pList);

//������ �߰� 
int list_add(List *pList, Data data);

//n��° ������ ����
int list_remove(List *pList, int n);

//n��° ������ ���� 
int list_set(List *pList, int n, Data data);

//������ ����
int list_length(List *pList);

//������ ��ȸ, iteration �ʱ�ȭ
void list_init_iter(List *pList);

//������ ��ȸ, iteration ���� ������ ����
Data list_next(List *pList);

//������ ��ȸ, iteration ���� �����Ͱ� �ֳ�?
int list_hasNext(List *pList);

//������ ��ȸ : n��° �����Ͱ� �б� 
int list_get(List *pList, int n, Data *pData);

//������ ���� 
int list_insert(List *pList, int n, Data data);

//�־��� List���� data�� ��� Node�� ã�Ƽ� ����, ������ NULL ����
Node *list_search(List* pList, Data data);








#endif