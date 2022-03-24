#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�

#include "BinarySearchTree.h"

#define SUCCESS 1
#define FAIL 0

// ����Ž��Ʈ�� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode **ppRoot) {
	*ppRoot = NULL;
}

// ����Ž��Ʈ���� ������� ������ ���� 
int bst_insert(BTreeNode **ppRoot, BTData data)
{
	BTreeNode *parentNode = NULL; //parent node
	BTreeNode *curNode = *ppRoot; // current node - �ϴ� root���� �����Ѵ�.
	BTreeNode *newNode = NULL; // new node ���� 

	// ���ο� ��尡 �߰��� ��ġ�� ã�´�.
	// root ���� �����Ͽ� ��ġ�� ã�������� ������ �����´�.
	while (curNode != NULL) // ���������� ����, �װ��� ���Ե� ��ġ (ppt���� BST 10�߰��ϴ� �׸� ����)
	{
		if (btree_get_data(curNode) == data)
			return FAIL; // BST������ key�� �ߺ��� ������� ����

		parentNode = curNode; // �ϴ� parent node�� current node �� �ΰ�... 

		if (btree_get_data(curNode) > data) 
			curNode = btree_get_left(curNode);
		// �����Ϸ��� �����Ͱ� ����� �����ͺ��� �� �۴ٸ�, current node�� left�� �̵�

		else
			curNode = btree_get_right(curNode);
		// �����Ϸ��� �����Ͱ� ����� �����ͺ��� �� �۴ٸ�, current node�� left�� �̵�
	}
	// parentNode �� �����忡 �߰��� �� ��� ����
	newNode = btree_make_node(); // �� ��� ����
	btree_set_data(newNode, data);

	// parentNode �� �����忡 �߰��� �� ��� �߰�
	if (parentNode != NULL)
	{
		if (btree_get_data(parentNode) > data)
			btree_make_left(parentNode, newNode);
		else
			btree_make_right(parentNode, newNode);
	}
	else // ù��° ����� ���, �� ��尡 ��Ʈ ��ġ�̴ϱ� parentNode�� NULL�̴�. 
	{
		*ppRoot = newNode; // ��Ʈ�� ����
		// ���������͸� ����� ����? 
	}

	return SUCCESS; 
}

// ����Ž��Ʈ���� ������� ������ Ž��, �߰��� ��� ����
BTreeNode* bst_search(BTreeNode *pRoot, BTData data)
{
	BTreeNode *curNode = pRoot; // root ���� Ž�� ����
	BTData curData;

	while (curNode != NULL) // Ž���� �ϴٰ� ������ �����Ѵٴ� ���� Ž�����ж�� �ǹ�
	{
		curData = btree_get_data(curNode); // ���� ����� ������

		if (data == curData)
			return curNode; // �߽߰� ��� ����, Ž�� ���� 

		if (data < curData) // �߰� �������� data ���� ���� ����� �����Ͱ��� ���Ͽ� ������ left, ũ�� right�� �̵� 
			curNode = btree_get_left(curNode);
		else
			curNode = btree_get_right(curNode);
		
	}

	return NULL; // Ž����� ����
}