#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺��� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

#define MAX_LENGTH 4

#define FALSE 0
#define TRUE 1

typedef struct _IterArray {
	int arr[MAX_LENGTH];
	int curPosition; //iterator ������ ���� �� 
} IterArray;

// iterator �ʱ�ȭ
void iter_init(IterArray *p) {
	printf("Iterator �ʱ�ȭ\n");
	p->curPosition = -1; 
	//�߿�@@@@@@@
	//(p->curPosition + 1 < MAX_LENGTH) ������ p->curPosition = -1; �� �ʱ�ȭ���Ѿ� �迭 0���� ��°��� 
}

// ������ ������ ������ �ֳ�?
int iter_hasNext(IterArray *p) {
	if (p->curPosition + 1 < MAX_LENGTH)
	{
		return TRUE;
	}
	else {
		printf("�� �̻� ������ �����Ͱ� �����ϴ�\n");
		return FALSE;
	}
}

// ���� ������ ����
int iter_next(IterArray *p) {
	p->curPosition++; //�켱 curPosition �� next�� 1 ���� 
	return p->arr[p->curPosition]; //curPostion�� ����Ű�� ���� �� ���� 
}

int main() {

	IterArray data = { {10,20,30,40}, -1 };

	IterArray *p = &data;

	iter_init(&data);

	while (iter_hasNext(&data)) //�� ������ �����Ͱ� �ִ°�?
	{
		printf("%d\n", iter_next(&data));
	}
	printf("\n");


	//�ٽ� iterator �� ������ �ϸ�...?

	//iter_init(&data);
	
	while (iter_hasNext(&data)) 
	{
		printf("%d\n", iter_next(&data));
	}
	printf("\n");
	
	//iterator�� ��ȸ���̹Ƿ� �ٽ� �������� iter_init(&data);�� �ʱ�ȭ�ؼ� ���۽��Ѿ���

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}

/* ���� ��κ��� ���� ���鿡�� Iteration(�ݺ���) ������.
*
*	Python �� iterable��ü
*		ex) for a in b:  <-- b �� 'iterable' �ؾ� �Ѵ�.
*
*	Java
*		Enhanced-for. ex) for(int n : list)
*		Collection �� Iterator ��ü
*
*	JavaScript
*		for ~ in
*		for ~ of
*		forEach
*	C++
*		iterator
*/

