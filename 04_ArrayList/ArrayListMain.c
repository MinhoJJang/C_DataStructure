#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 
#include "ArrayList.h"

void printList(List *pList) {
	list_init_iter(pList); //iteration ����
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
	
	list_add(&myList, 100); // ������ �߰� 
	printList(&myList);		   // [100]
	list_add(&myList, 50);   // ������ �߰� 
	printList(&myList);		   // [100, 50]
	list_add(&myList, 100);
	printList(&myList);			   // [100, 50, 100]
	list_add(&myList, 20);
	printList(&myList);			   // [100, 50, 100, 20]
	list_add(&myList, 45);
	printList(&myList);				   // ������ �߰� ����
	list_add(&myList, 75);
	printList(&myList);				   // ������ �߰� ����

	//������ ���� 
	list_set(&myList, 0, 40); //0��° �����͸� 100->40���� ���� 
	list_set(&myList, 1, 30);
	list_set(&myList, 4, 30); // ���� ����
	printList(&myList);			// [40,30,100,20]

	//������ ���� 
	printf("������ ������ %d\n", list_length(&myList)); //4

	//n��° ������ ��ȸ 
	Data data;
	if (list_get(&myList, 0, &data)) printf("0��° : %d\n", data); //40
	if (list_get(&myList, 6, &data)) printf("6��° : %d\n", data); //FAIL
	if (list_get(&myList, 2, &data)) printf("2��° : %d\n", data); //100

	// ������ ���� 
	printf("������\n");
	printList(&myList); // [40,30,100,20]

	list_remove(&myList, 2); // 100 ���� 
	printList(&myList); // [40,30,20]

	list_remove(&myList, 2); // 20 ���� 
	printList(&myList); // [40,30]

	printf("������ ������ %d\n", list_length(&myList)); //2

	list_remove(&myList, 0); // 40 ���� 
	printList(&myList); // [30]

	list_remove(&myList, 0); // 30 ���� 
	printList(&myList); // []

	list_remove(&myList, 0); // �����Ұ� ���� - ����
	printf("������ ������ %d\n", list_length(&myList)); //0

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
	printf("������ ������ %d\n", list_length(&myList)); //4

	list_init(&myList);
	list_insert(&myList, 0, 5); // insert �� list �� ���� �߰� (add) �����ϰ� ���۽�Ű�� 
	printList(&myList); // [5]
	list_insert(&myList, 1, 25); 
	printList(&myList); // [5, 25]
	list_insert(&myList, 2, 45); 
	printList(&myList); //[5, 25, 45]

	// ����Ʈ ����
	list_destroy(&myList);  

	{
		printf("--------------------------------------------------------\n");
		list_init(&myList);
		unsigned int test_size = 30000;
		clock_t start, end;
		Data data;
		printf("�������ϸ� ����: ������ - �ƹ�Ű�� ��������\n");
		_getch();

		printf("%d�� insert...\n", test_size);

		//�������ϸ� 
		start = clock();

		for (unsigned int i = 0; i < test_size; i++) {
			list_insert(&myList, 0, i); //0��° insert~
		}

		end = clock();

		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("insert ���: %ld ms ���\n", end - start);

		//----------------------------------------
		printf("�ƹ�Ű�� �����ø� ���� �׽�Ʈ �����մϴ�\n");
		_getch();
		printf("%d �� get...\n", test_size);

		// �������ϸ�
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++) {
			list_get(&myList, i, &data);
		}
		end = clock();
		
		printf("get ���: %ld ms ���\n", end - start);

		//---------------------------------
		printf("�ƹ�Ű�� ������ ������ ���۵˴ϴ�: ������\n");
		_getch();
		printf("%d �� remove...\n", test_size);
		start = clock(); //�ð� ���� ����
		for (unsigned int i = 0; i < test_size; i++)
		{
			list_remove(&myList, 0);
		}
		end = clock(); //�ð� ���� ��
		printf("���� ����Ʈ size : %d\n", list_length(&myList));
		printf("remove ��� : %ld ms ���\n", end - start);

		//========================
		printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
		_getch();
		list_destroy(&myList);
	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}