#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 
//#include "ListBaseStack.h"
#include "PracticeStack.h"

int main() { //Data main �� ����.. 

	Stack stack;
	Data data;

	stack_init(&stack); // ���� ���� �� �ʱ�ȭ

	// ������ push 
	// https://visualgo.net/en/list
	stack_push(&stack, 1); // 1
	stack_push(&stack, 2); // 2 - 1
	stack_push(&stack, 3); // 3 - 2 - 1
	stack_push(&stack, 4); // 4 - 3 - 2 - 1
	stack_push(&stack, 5); // 5 - 4 - 3 - 2 - 1

	//������ pop 
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data); // 5
	stack_pop(&stack, &data);
	printf("pop--> %d\n", data); // 4

	while (!stack_is_empty(&stack)) { // ������ �� ������ // 3 , 2 , 1
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	for (int i = 100; i <= 500; i += 100) {
		stack_push(&stack, i);
	}

	stack_peek(&stack, &data);
	printf("peek->%d\n", data);

	while (!stack_is_empty(&stack)) {
		// 1000, 900, 800, ... , 100
		stack_pop(&stack, &data);
		printf("pop--> %d\n", data);
	}

	stack_peek(&stack, &data);
	printf("peek->%d\n", data);

	stack_pop(&stack, &data);
	printf("pop--> %d\n", data);

	stack_destroy(&stack); // �������� 

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}