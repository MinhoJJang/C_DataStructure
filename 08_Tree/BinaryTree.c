#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

#ifndef __QUEUE_H__
#define __QUEUE_H__

#define SUCCESS	1
#define FAIL	0

// Queue.h�νĺҰ������� �׳� �տ��� ������ 
/* ť�� ������ */
typedef int Data;

typedef struct _node
{
	Data data;
	struct _node *pNext;
} Node;

typedef struct _queue
{
	Node *pFront;
	Node *pBack;
} ListQueue;

typedef ListQueue Queue;

/* ť�� ���� */
// ť �ʱ�ȭ
void queue_init(Queue *pq);

// ť ����
void queue_destroy(Queue *pq);

// ť�� ����ִ���?
int queue_is_empty(Queue *pq);

// enqueue, ������ �߰� (back �� �߰�)
int queue_enq(Queue *pq, Data data);

// dequeue, ������ ������ (front ���� ����)
int queue_deq(Queue *pq, Data *pData);

// peek, ������ �鿩�� ���� (front)
int queue_peek(Queue *pq, Data *pData);

#endif

#include "BinaryTree.h"

//Ʈ�� ��� ���� 
BTreeNode* btree_make_node(void) {

	BTreeNode *pNewNode = (BTreeNode *)malloc(sizeof(BTreeNode));

	pNewNode->pLeft = NULL;
	pNewNode->pRight = NULL;
	pNewNode->data = 0;

	return pNewNode;
}

// ��� ������ �б�
BTData btree_get_data(BTreeNode *bt) {
	return bt->data;
}

// ��� ������ ����
void btree_set_data(BTreeNode *bt, BTData data) {
	bt->data = data;
}

// ����� left sub tree 
BTreeNode* btree_get_left(BTreeNode *bt) {
	return bt->pLeft;
}

// ����� right sub tree 
BTreeNode* btree_get_right(BTreeNode *bt) {
	return bt->pRight;
}

// bt�� left �� sub tree ����
void btree_make_left(BTreeNode *bt, BTreeNode *sub) {
	if (bt->pLeft != NULL)
		btree_delete(bt->pLeft);

	bt->pLeft = sub;
}

// bt�� right �� sub tree ����
void btree_make_right(BTreeNode *bt, BTreeNode *sub) {
	if (bt->pRight != NULL)
		btree_delete(bt->pRight);

	bt->pRight = sub;
}

// ���� ������ ���� 
void btree_delete(BTreeNode *bt) {
	if (bt == NULL) return;

	// ������ post order ���(L -> R -> C) ������ ������ �Ѵ�
	// �ڱ� �ڽ��� ����� ���� left, right ���� ������ �Ѵ�

	btree_delete(bt->pLeft); // Left Clear 
	btree_delete(bt->pRight); // Right Clear

	printf("Node Clear: %d \n", bt->data);
	free(bt); // Center Clear
}

//Traversing 

void btree_preorder_traverse(BTreeNode *bt, fnVistNode action) 
{
	if (bt == NULL) return; // ������� 

	// C->L->R
	action(bt->data); // C
	btree_preorder_traverse(bt->pLeft, action); // L:���ȣ��
	btree_preorder_traverse(bt->pRight, action); // R:���ȣ��
}

void btree_inorder_traverse(BTreeNode *bt, fnVistNode action)
{
	if (bt == NULL) return; // ������� 

	// L->C->R
	btree_inorder_traverse(bt->pLeft, action); // L:���ȣ��
	action(bt->data); // C
	btree_inorder_traverse(bt->pRight, action); // R:���ȣ��
}

void btree_postorder_traverse(BTreeNode *bt, fnVistNode action)
{
	if (bt == NULL) return; // ������� 

	// L>R->C
	btree_postorder_traverse(bt->pLeft, action); // L:���ȣ��
	btree_postorder_traverse(bt->pRight, action); // R:���ȣ��
	action(bt->data); // C
}

void btree_levelorder_traverse(BTreeNode *bt, fnVistNode action) 
{
	Queue q;
	queue_init(&q, (Data)bt);

	// �ϴ� root�� ���� enq
	queue_enq(&q, bt);

	while (!queue_is_empty(&q))
	{
		//deq�Ͽ� ���
		BTreeNode *btCurrent;
		queue_deq(&q, &btCurrent);
		action(btCurrent->data);

		//left�� enq
		if (btCurrent->pLeft != NULL)
			queue_enq(&q, btCurrent->pLeft);

		//right�� enq 
		if (btCurrent->pRight != NULL)
			queue_enq(&q, btCurrent->pRight);
	}
}

