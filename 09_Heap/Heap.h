#ifndef __HEAP_H__
#define __HEAP_H__

#define HEAP_LEN 100

#define SUCCESS 1
#define FAIL 0
/* Heap�� ������*/

typedef int HData;

typedef int fnPriorityComp(HData d1, HData d2);
// �� �����͸� ���� � ���� ũ�ų� ������ �˾Ƴ��� �Լ�-�� Ÿ���� �����Ѱ���.. 
// d1�� �켱������ ���ٸ� 0���� ū �� ���� 
// d2�� �켱������ ���ٸ� 0���� ���� �� ���� 
// d1 = d2�� 0����

typedef struct _heap
{
	HData heapArr[HEAP_LEN]; // �迭

	int numData; // ����ִ� �����Ͱ��� 

	fnPriorityComp *comp; // �켱���� ���Լ� 
	// �Լ�Ÿ�� ������ comp
} Heap;

/* Heap�� ����*/

// �� �ʱ�ȭ
void heap_init(Heap *ph, fnPriorityComp pc);

// ���� ����ִ���? 
int heap_is_empty(Heap *ph);

// ���� ������ �߰� insert
void heap_insert(Heap *ph, HData data);

// ���� ������ ���� delete
HData heap_delete(Heap *ph);

#endif 
