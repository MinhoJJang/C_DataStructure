#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 
#define DATA_SIZE 80000
#include "LinkedList.h"
#include "BinarySearchTree.h"

// �迭����
void shuffleArr(int arr[], int n)
{
	srand(time(NULL));
	if (n > 1) {
		for (int i = 0; i < n - 1; i++) {
			// i �� ������ i �������� j ��°�� swap
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

void printArr(int arr[], int n) {
	printf("[ ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("]\n");
}


// �������� �迭
void genIncSorted(int arr[], int n) {

	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
}

// ������ �迭 1~n ���� 
void genRandom(int arr[], int n) {
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}


// �������� �迭
void genDecSorted(int arr[], int n) {
	for (int i = 0; i < n; i++)
		arr[i] = n - i;
}

// �迭�κ��� List ����
void genList(List *pList, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		list_add(pList, arr[i]);
} // ����Ʈ�� �迭���ִ� �� �����ڱ�

// �迭�κ��� BST ���� 
void genBST(BTreeNode **ppRoot, int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		bst_insert(ppRoot, arr[i]);
	}
}

// ------------------------------
typedef void* fnSearch(void*, int); // �˻��Լ� Ÿ��

// collection ���� arr[] �� data ���� Ž���Ͽ� 
// ��� �˻� �ð��� üũ 

void chkTimeLapArray(fnSearch search, void* collection, int arr[], int n, char *title)
{
	clock_t start, end;
	long duration = 0; // �����ջ� �ð�
	int cnt = 0; //Ž�� ���� Ƚ��

	// �� �������� search�� �ɸ��� �ð��� ����� ���Ѵ�.
	for (int i = 0; i < n; i++) {
		start = clock();

		//Ž�� 
		if (search(collection, arr[i]) != NULL) cnt++;

		end = clock();
		duration += end - start;
	}

	printf("%s (%d/%d �� Ž��) ������: %.3f ms\n", title, cnt, n, (double)duration / n);

;
}

int main() {

	int srcArr[DATA_SIZE];
	genIncSorted(srcArr, DATA_SIZE);

	int workArr[DATA_SIZE];

	memcpy(workArr, srcArr, sizeof(int)*DATA_SIZE);
	shuffleArr(workArr, DATA_SIZE);

	/*List list;
	list_init(&list);
	genList(&list, workArr, DATA_SIZE);
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "����ƮŽ��");

	list_destroy(&list);*/

	BTreeNode *pRoot; // BST�� ��Ʈ
	bst_make_init(&pRoot);

	//genBST(&pRoot, srcArr, 10); // 1���� 10���� insert
	//BTreeNode *p = NULL;
	//for (int i = 1; i <= 10; i++) {
	//	if (p = bst_search(pRoot, i))
	//		printf("�߰� %d\n", p->data);
	//}

	genBST(&pRoot, workArr, DATA_SIZE); // BST�� workArr�� ����ֱ�
	chkTimeLapArray(bst_search, pRoot, srcArr, DATA_SIZE, "BSTŽ��");

	btree_delete(pRoot);


	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}