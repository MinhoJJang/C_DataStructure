#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#define DATA_SIZE 80000
#include "LinkedList.h"
#include "BinarySearchTree.h"

// 배열섞기
void shuffleArr(int arr[], int n)
{
	srand(time(NULL));
	if (n > 1) {
		for (int i = 0; i < n - 1; i++) {
			// i 와 임의의 i 오른쪽의 j 번째와 swap
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


// 오름차순 배열
void genIncSorted(int arr[], int n) {

	for (int i = 0; i < n; i++)
		arr[i] = i + 1;
}

// 무작위 배열 1~n 범위 
void genRandom(int arr[], int n) {
	genIncSorted(arr, n);
	shuffleArr(arr, n);
}


// 내림차순 배열
void genDecSorted(int arr[], int n) {
	for (int i = 0; i < n; i++)
		arr[i] = n - i;
}

// 배열로부터 List 생성
void genList(List *pList, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		list_add(pList, arr[i]);
} // 리스트에 배열에있는 값 때려박기

// 배열로부터 BST 생성 
void genBST(BTreeNode **ppRoot, int arr[], int n)
{
	for (int i = 0; i < n; i++) {
		bst_insert(ppRoot, arr[i]);
	}
}

// ------------------------------
typedef void* fnSearch(void*, int); // 검색함수 타입

// collection 에서 arr[] 의 data 들을 탐색하여 
// 평균 검색 시간을 체크 

void chkTimeLapArray(fnSearch search, void* collection, int arr[], int n, char *title)
{
	clock_t start, end;
	long duration = 0; // 누적합산 시간
	int cnt = 0; //탐색 성공 횟수

	// 각 개별적인 search에 걸리는 시간의 평균을 구한다.
	for (int i = 0; i < n; i++) {
		start = clock();

		//탐색 
		if (search(collection, arr[i]) != NULL) cnt++;

		end = clock();
		duration += end - start;
	}

	printf("%s (%d/%d 개 탐색) 수행결과: %.3f ms\n", title, cnt, n, (double)duration / n);

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
	chkTimeLapArray(list_search, &list, srcArr, DATA_SIZE, "리스트탐색");

	list_destroy(&list);*/

	BTreeNode *pRoot; // BST의 루트
	bst_make_init(&pRoot);

	//genBST(&pRoot, srcArr, 10); // 1부터 10까지 insert
	//BTreeNode *p = NULL;
	//for (int i = 1; i <= 10; i++) {
	//	if (p = bst_search(pRoot, i))
	//		printf("발견 %d\n", p->data);
	//}

	genBST(&pRoot, workArr, DATA_SIZE); // BST에 workArr을 집어넣기
	chkTimeLapArray(bst_search, pRoot, srcArr, DATA_SIZE, "BST탐색");

	btree_delete(pRoot);


	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}