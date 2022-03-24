#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수

#include "BinarySearchTree.h"

#define SUCCESS 1
#define FAIL 0

// 이진탐색트리 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot) {
	*ppRoot = NULL;
}

// 이진탐색트리를 대상으로 데이터 저장 
int bst_insert(BTreeNode **ppRoot, BTData data)
{
	BTreeNode *parentNode = NULL; //parent node
	BTreeNode *curNode = *ppRoot; // current node - 일단 root부터 시작한다.
	BTreeNode *newNode = NULL; // new node 생성 

	// 새로운 노드가 추가될 위치를 찾는다.
	// root 부터 시작하여 위치를 찾을때까지 밑으로 내려온다.
	while (curNode != NULL) // 종단점까지 가면, 그곳이 삽입될 위치 (ppt에서 BST 10추가하는 그림 참조)
	{
		if (btree_get_data(curNode) == data)
			return FAIL; // BST에서는 key의 중복을 허용하지 않음

		parentNode = curNode; // 일단 parent node를 current node 로 두고... 

		if (btree_get_data(curNode) > data) 
			curNode = btree_get_left(curNode);
		// 삽입하려는 데이터가 노드의 데이터보다 더 작다면, current node를 left로 이동

		else
			curNode = btree_get_right(curNode);
		// 삽입하려는 데이터가 노드의 데이터보다 더 작다면, current node를 left로 이동
	}
	// parentNode 의 서브노드에 추가할 새 노드 생성
	newNode = btree_make_node(); // 새 노드 생성
	btree_set_data(newNode, data);

	// parentNode 의 서브노드에 추가할 새 노드 추가
	if (parentNode != NULL)
	{
		if (btree_get_data(parentNode) > data)
			btree_make_left(parentNode, newNode);
		else
			btree_make_right(parentNode, newNode);
	}
	else // 첫번째 노드인 경우, 새 노드가 루트 위치이니까 parentNode는 NULL이다. 
	{
		*ppRoot = newNode; // 루트에 세팅
		// 이중포인터를 사용한 이유? 
	}

	return SUCCESS; 
}

// 이진탐색트리를 대상으로 데이터 탐색, 발견한 노드 리턴
BTreeNode* bst_search(BTreeNode *pRoot, BTData data)
{
	BTreeNode *curNode = pRoot; // root 부터 탐색 시작
	BTData curData;

	while (curNode != NULL) // 탐색을 하다가 종단점 도달한다는 것은 탐색실패라는 의미
	{
		curData = btree_get_data(curNode); // 현재 노드의 데이터

		if (data == curData)
			return curNode; // 발견시 노드 리턴, 탐색 종료 

		if (data < curData) // 발견 못했으면 data 값과 현재 노드의 데이터값과 비교하여 작으면 left, 크면 right로 이동 
			curNode = btree_get_left(curNode);
		else
			curNode = btree_get_right(curNode);
		
	}

	return NULL; // 탐색결과 없음
}