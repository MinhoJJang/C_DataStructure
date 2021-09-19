#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/* Binary Tree 데이터 */
typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *pLeft; //left child node 
	struct _bTreeNode *pRight; //right child node
} BTreeNode;

/* Binary Tree 동작 */
//트리 노드 생성 
BTreeNode* btree_make_node(void);

// 노드 데이터 읽기
BTData btree_get_data(BTreeNode *bt);

// 노드 데이터 쓰기
void btree_set_data(BTreeNode *bt, BTData data);

// 노드의 left sub tree 
BTreeNode* btree_get_left(BTreeNode *bt);

// 노드의 right sub tree 
BTreeNode* btree_get_right(BTreeNode *bt);

// bt의 left 에 sub tree 연결
void btree_make_left(BTreeNode *bt, BTreeNode *sub);

// bt의 right 에 sub tree 연결
void btree_make_right(BTreeNode *bt, BTreeNode *sub);

// 현재 노드부터 삭제 
void btree_delete(BTreeNode *bt);

// Traversing-----------------------------------
// 노드를 visit 하여 노드의 데이터에 대해 수행할 함수 (함수포인터) 타입 선언

typedef void fnVistNode(BTData data);

// 주어진 노드 bt 부터 시작하여 traversing 하면서 
// node 를 visit 할때마다 action() 수행
void btree_preorder_traverse(BTreeNode *bt, fnVistNode action);
void btree_inorder_traverse(BTreeNode *bt, fnVistNode action);
void btree_postorder_traverse(BTreeNode *bt, fnVistNode action);

void btree_levelorder_traverse(BTreeNode *bt, fnVistNode action);






#endif // !__BINARY_TREE_H__

