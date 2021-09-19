#ifndef __BST_H__
#define __BST_H__

#include "BinaryTree.h"
#define SUCCESS 1
#define FAIL 0

// 이진탐색트리 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot);

// 이진탐색트리를 대상으로 데이터 저장 
int bst_insert(BTreeNode **ppRoot, BTData data);

// 이진탐색트리를 대상으로 데이터 탐색, 발견한 노드 리턴
BTreeNode* bst_search(BTreeNode *pRoot, BTData data);

#endif // !__BST_H__

