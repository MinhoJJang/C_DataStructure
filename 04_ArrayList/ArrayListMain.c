#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#include "ArrayList.h"

void printList(List *pList) {
	list_init_iter(pList); //iteration 시작
	printf("[ ");
	while (list_hasNext(pList)) {
		printf("%d,", list_next(pList));
	}
	printf("\b]\n"); // \b => backspace
}

int main() {

	List myList;
	list_init(&myList);
	//List *pList = &myList;

	printList(&myList);
	
	list_add(&myList, 100); // 데이터 추가 
	printList(&myList);		   // [100]
	list_add(&myList, 50);   // 데이터 추가 
	printList(&myList);		   // [100, 50]
	list_add(&myList, 100);
	printList(&myList);			   // [100, 50, 100]
	list_add(&myList, 20);
	printList(&myList);			   // [100, 50, 100, 20]
	list_add(&myList, 45);
	printList(&myList);				   // 데이터 추가 실패
	list_add(&myList, 75);
	printList(&myList);				   // 데이터 추가 실패

	//데이터 수정 
	list_set(&myList, 0, 40); //0번째 데이터를 100->40으로 수정 
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); // 수정 실패
	printList(&myList);			// [40,30,100,20]

	//데이터 개수 
	printf("데이터 개수는 %d\n", list_length(&myList)); //4

	//n번째 데이터 조회 
	Data data;
	if (list_get(&myList, 0, &data)) printf("0번째 : %d\n", data); //40
	if (list_get(&myList, 6, &data)) printf("6번째 : %d\n", data); //FAIL
	if (list_get(&myList, 2, &data)) printf("2번째 : %d\n", data); //100

	// 데이터 삭제 
	printf("삭제전\n");
	printList(&myList); // [40,30,100,20]

	list_remove(&myList, 2); // 100 삭제 
	printList(&myList); // [40,30,20]

	list_remove(&myList, 2); // 20 삭제 
	printList(&myList); // [40,30]

	printf("데이터 개수는 %d\n", list_length(&myList)); //2

	list_remove(&myList, 0); // 40 삭제 
	printList(&myList); // [30]

	list_remove(&myList, 0); // 30 삭제 
	printList(&myList); // []

	list_remove(&myList, 0); // 삭제할게 없음 - 실패
	printf("데이터 개수는 %d\n", list_length(&myList)); //0

	// insert 
	printf("-----------data insert-----------\n");
	list_add(&myList, 10);
	list_add(&myList, 20);
	printList(&myList); // [10, 20]
	list_insert(&myList, 1, 40); // [10, 40, 20]
	printList(&myList);
	list_insert(&myList, 0, 5); // [5, 10, 40, 20]
	printList(&myList);
	list_insert(&myList, 0, 5); // FAIL
	printList(&myList);
	printf("데이터 개수는 %d\n", list_length(&myList)); //4

	list_init(&myList);
	list_insert(&myList, 0, 5); // insert 는 list 의 끝에 추가 (add) 가능하게 동작시키기 
	printList(&myList); // [5]
	list_insert(&myList, 1, 25); 
	printList(&myList); // [5, 25]
	list_insert(&myList, 2, 45); 
	printList(&myList); //[5, 25, 45]

	// 리스트 제거
	list_destroy(&myList);  

	{
		printf("--------------------------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("프로파일링 시작: 스냅샷 - 아무키나 누르세요\n");
		_getch();

		printf("%d개 insert...\n", test_size);

		//프로파일링 
		start = clock();

		for (unsigned int i = 0; i < test_size; i++) {
			list_insert(&myList, 0, i); //0번째 insert~
		}

		end = clock();

		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("insert 결과: %ld ms 경과\n", end - start);

		//----------------------------------------
		printf("아무키나 누르시면 다음 테스트 진행합니다\n");
		_getch();
		printf("%d 개 get...\n", test_size);

		// 프로파일링
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++) {
			list_get(&myList, i, &data);
		}
		end = clock();
		
		printf("get 결과: %ld ms 경과\n", end - start);

		//---------------------------------
		printf("아무키나 누르면 삭제가 시작됩니다: 스냅샷\n");
		_getch();
		printf("%d 개 remove...\n", test_size);
		start = clock(); //시간 측정 시작
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0);
		}
		end = clock(); //시간 측정 끝
		printf("현재 리스트 size : %d\n", list_length(&myList));
		printf("remove 결과 : %ld ms 경과\n", end - start);

		//========================
		printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
		_getch();
		list_destroy(&myList);
	}

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}