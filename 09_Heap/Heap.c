#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 
#include "Heap.h"

#define SUCCESS 1
#define FAIL 0

// -----------------------------------------
// �θ��� �ε��� 
int getParentIdx(int idx) {
	return idx / 2;
}

// left �ڽĳ�� �ε��� 
int getLeftIdx(int idx) {
	return idx * 2;
}

// right �ڽĳ�� �ε��� 
int getRightIdx(int idx) {
	return idx * 2 + 1;
}

// idx�� �ڽĵ� �� �켱������ ���� �ڽ��� index�� ���� --> delete �� ��� 
int getHighPriority(Heap *ph, int idx)
{
	// �ڽĳ�尡 ���ٸ� 0���� 
	if (getLeftIdx(idx) > ph->numData) return 0;

	// �ڽĳ�尡 1����� (���� ��尡 ����)
	if (getLeftIdx(idx) == ph->numData) return getLeftIdx(idx);

	// �켱���� 
	if (ph->comp(ph->heapArr[getLeftIdx(idx)], ph->heapArr[getRightIdx(idx)]) < 0) {
		idx = getRightIdx(idx);
	}
	else {
		idx = getLeftIdx(idx);
	}

	/*if (ph->heapArr[getLeftIdx(idx)] >= ph->heapArr[getRightIdx(idx)]) {
		idx = getLeftIdx(idx);
	}
	else {
		idx = getRightIdx(idx);
	} */
	//��� �ص� ������ �츮�� comp�Լ��� ������ �װ� ����
	
	return idx;

}

// �� �ʱ�ȭ
void heap_init(Heap *ph, fnPriorityComp pc) {
	ph->numData = 0; // ������(���)���� 0
	ph->comp = pc; 
	// fnPriority...�� �̷��� Ÿ���� �Լ��� �ִ�..�� ���� �˷��ִ°��̰� DataPriorityComp �� '�׷��� Ÿ��'�� �Լ�. 
}

// ���� ����ִ���? 
int heap_is_empty(Heap *ph) {
	if (ph->numData == 0) return SUCCESS;
	return FAIL;
}

// ���� ������ �߰� insert
void heap_insert(Heap *ph, HData data) {

	// ���� insert�Ǵ� �����ʹ� �� ������ ���� 
	int idx = ph->numData + 1;
	// ph->numData �� �����ִ� ��尳���̹Ƿ� ���� ���� ���� idx�� ��尳��+1��°�� �����Ѵ�. 
	// ���� �迭 �ε����� �迭�� 0���� �����ϴ� �Ͱ��� �ٸ��� 1���� �����Ѵ�. �׷��� �θ��ڽ��� �ε������� ���� �������� ���ԵǾ� ����� ���ϱ� ����

	// �Ʒ� while �� �����ϸ鼭 ���� INSERT�� data�� ��ġ�� idx�� ���� (���� �����ϴ°� �ƴ�. ���� ��ġ�� �����ϴ°�)
	while (idx != 1) // root (�ֻ���) �� �����Ҷ� ����
	{
		// �θ�� �켱���� �� 
		if (ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0) // �θ𺸴� �켱������ ���ٸ�
		{
			// �θ� �������
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];

			// idx �� �θ��� idx�� �̵� 
			idx = getParentIdx(idx);

		}
		// ���� ���� ���� ��ȣ�� idx�� 
		else // �θ𺸴� �켱������ ���ų� ����.. ���⼭ while �������
		{
			break;
		}
	}

	// idx�� ������ �װ��� ���� INSERT�� data�� �� ��ġ 

	ph->heapArr[idx] = data;
	ph->numData++;

}

// ���� ������ ���� delete. ������ root���� �߻� 
int heap_delete(Heap *ph) {

	// root�� ���ֱ� 
	HData rootData = ph->heapArr[1]; // �ε��� 1���� ��Ʈ ���, �̸� �����ϰ� ���� 

	// ������ ��尡 �ڸ����� ��ġ idx �� �����ؾ� �Ѵ� .
	// idx�� �����ɶ����� ������ ����� data�� ������ ���´�. 

	HData lastElem = ph->heapArr[ph->numData];
	// ����������� ���� �����س��� 

	int idx = 1; // ������ ��尡 �ϴ� root �ڸ��� ���� �ȴ�. 
	int childIdx; 

	//// �ϴ�, �ڽĳ���� �켱���� ������ ����
	//childIdx = getHighPriority(ph, 1);

	//	// �Ʒ� while ���� �ᱹ idx ���� �����ϱ� ����.
	//	while (ph->comp(ph->heapArr[childIdx], ph->heapArr[idx]) < 0) {
	//		// ���õ� �ڽİ�, �Ʒ����� �ö�� ������ ���� �켱���� ��. 
	//		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����

	//		ph->heapArr[idx] = ph->heapArr[childIdx];
	//		// �ڽ��� �켱������ �� ũ�ٸ�,  �� �ڽ��� �θ��� �ڸ��� ��ü

	//		idx = childIdx;
	//		// ���� �񱳸� ���� ������ ��� idx�� ������ �ڽ���ġ�� ������
	//	
	//		if (ph->numData < (idx * 2)) {
	//			break;
	//		} // ���� �ڽ��� �ϳ��� ���ٸ� 0�� ���ϵǾ� while �� ���� 
	//		  // while������ ������ ó������ �ʳ�? �־���ϴ� ���ǽ��ΰ�?

	//		childIdx = getHighPriority(ph, idx);
	//		// ���õ� �ڽĳ�� �ε����� �ٽ� ���ϱ� 
	//	}

	while (childIdx = getHighPriority(ph, idx)) 
		// �� ���Կ����� ��ü�� ������� ����. ������ �� ��ü�� �������. 
	{
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0) break;

		ph->heapArr[idx] = ph->heapArr[childIdx];

		idx = childIdx;
	}

	ph->heapArr[idx] = lastElem;
	//ph->heapArr[ph->numData] = NULL;
	ph->numData--;
	

	return rootData;
}


	