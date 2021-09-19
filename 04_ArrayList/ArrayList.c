#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 

#include "ArrayList.h"

	// 리스트 초기화
	void list_init(List *pList) {
		pList->numData = 0;
		pList->curPosition = -1; //for iteration
		memset(pList->arr, 0, sizeof(pList->arr)); //배열 전부 0으로 초기화 
		printf("리스트 초기화\n");
	}

	// 리스트 제거 
	void list_destroy(List *pList) {
		pList->numData = 0;
		printf("리스트 제거\n");
	}

	//데이터 추가 
	int list_add(List *pList, Data data) {
		if (pList->numData >= LIST_LEN)
		{
			printf("데이터 추가 불가\n");
			return FAIL;
		}

		pList->arr[pList->numData] = data; //데이터 추가

		//printf("[%d] 번째 데이터 %d 추가\n", pList->numData, data);
		(pList->numData)++; //데이터 개수 증가 
		return SUCCESS;
	}

	//n번째 데이터 삭제
	int list_remove(List *pList, int n) {

		if (n >= pList->numData) {
			//printf("[%d] 번째 데이터 삭제 실패\n", n);
			return FAIL;
		}

		for (int i = n; i < pList->numData-1; i++) {
			pList->arr[i] = pList->arr[i + 1];
			//pList->arr[i + 1] = NULL;
		}
		(pList->numData)--;
	}

	//n번째 데이터 수정 
	int list_set(List *pList, int n, Data data) {

		if (n >= pList->numData) {
			printf("%d 번째 데이터 수정 실패\n", n);
			return FAIL;
		}

		printf("[%d] 번째 데이터 수정 %d --> %d\n", n, pList->arr[n], data);
		pList->arr[n] = data; // 수정
		return SUCCESS; 
	}

	//데이터 개수
	int list_length(List *pList) {
		return pList->numData;
	}

	//데이터 조회, iteration 초기화
	void list_init_iter(List *pList) {

		pList->curPosition = -1;
	}

	//데이터 조회, iteration 다음 데이터 추출
	Data list_next(List *pList) {

		pList->curPosition++;
		Data result = pList->arr[pList->curPosition];

		return result;
	}

	//데이터 조회, iteration 다음 데이터가 있나?
	int list_hasNext(List *pList) {

		if (pList->curPosition + 1 < pList->numData)
			return SUCCESS;

		return FAIL;
	}

	//데이터 조회 : n번째 데이터값 읽기 
	int list_get(List *pList, int n, Data *pData) {
		if (n >= pList->numData) {
			return FAIL;
		}

		*pData = pList->arr[n]; //n번째 데이터값을 pData를 통헤 전달 Call By Reference 
		return SUCCESS;
	}

	//n번째 위치에 데이터 삽입
	int list_insert(List *pList, int n, Data data) {
		if (pList->numData >= LIST_LEN || n> pList->numData) {
			printf("[%d] 번째 위치에 데이터 삽입 불가\n", n);
			return FAIL;
		}
		else 
		{
			for (int i = pList->numData; i > n ; i--) {
				pList->arr[i] = pList->arr[i-1];
			}
			
			pList->arr[n] = data;
			pList->numData++;
		//	printf("[%d] 번째 위치에 데이터 %d 삽입 성공\n", n, data);

			return SUCCESS;
		}
	}
	
	// 기존의 n번째 부터 한칸씩 뒤로 밀려나야 한다.
	// 맨 뒤에서부터!!! 부터 n 앞의 것들은 한칸씩 우측으로 복사


