#include <stdio.h>
#include <stdlib.h>				// malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h>				//strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <time.h>				// clock .. �ð�, ��¥ �Լ�
#pragma warning(disable : 4996) // scnaf() �� ���� c�Լ��� ���۹���.
#pragma warning(disable : 4477) // unsigned <--> signed ���� warning ����
#include "HeapSort.h"

#define SUCCESS 1
#define FAIL 0
#define ROOTIDX 1

// -----------------------------------------
// ��� �ε��� ��� ��ũ�� (���� ���)
#define GET_PARENT_IDX(idx) ((idx) >> 1) // idx/2 �������� shift����
// �Լ�ȣ���� �ƴ϶� �ش� �Լ��� �׳� ���Խ�Ŵ. �ð��� �̵�
#define GET_LEFT_IDX(idx) ((idx) << 1)		  // idx*2 = �������� 1ĭ
#define GET_RIGHT_IDX(idx) (((idx) << 1) + 1) // ��������ڰ� ��Ʈ�����ں��� �켱������ ũ�Ƿ� ��ȣ �����ֱ�

// ���Լ� ��� ��ũ�� (���� up)
#define COMP_ASC(d1, d2) ((d2) - (d1))	// ��������
#define COMP_DESC(d1, d2) ((d1) - (d2)) // ��������

// idx�� �ڽĵ� �� �켱������ ���� �ڽ��� index�� ���� --> delete �� ���
int getHighPriority(Heap *ph, int idx)
{
	// �ڽĳ�尡 ���ٸ� 0����
	if (GET_LEFT_IDX(idx) > ph->numData)
		return 0;

	// �ڽĳ�尡 1����� (���� ��尡 ����)
	if (GET_LEFT_IDX(idx) == ph->numData)
		return GET_LEFT_IDX(idx);

	// �켱����
	if (COMP_ASC(ph->heapArr[GET_LEFT_IDX(idx)], ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)
	{
		idx = GET_RIGHT_IDX(idx);
	}
	else
	{
		idx = GET_LEFT_IDX(idx);
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
void heap_init(Heap *ph, int len)
{
	ph->numData = 0; // ������(���)���� 0
	ph->heapArr = (int *)malloc(sizeof(int) * (len + 1));
	// complete binary tree�� �迭�� 1������ �����ϹǷ� 0���� ���� ����. �׷��� len+1��ŭ�� size�� �ʿ���. �̷��� �迭�� 1-based �迭�̶�� �θ�

	g_hp = ph; // �����Ŀ� �ʿ�. parameter�� ���̱� ���ؼ�
}

void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	memset(ph, 0, sizeof(Heap));
}

// ���� ����ִ���?
int heap_is_empty(Heap *ph)
{
	if (ph->numData == 0)
		return SUCCESS;
	return FAIL;
}

// ���� ������ �߰� insert
void heap_insert(Heap *ph, HData data)
{

	// ���� insert�Ǵ� �����ʹ� �� ������ ����
	int idx = ph->numData + 1;
	// ph->numData �� �����ִ� ��尳���̹Ƿ� ���� ���� ���� idx�� ��尳��+1��°�� �����Ѵ�.
	// ���� �迭 �ε����� �迭�� 0���� �����ϴ� �Ͱ��� �ٸ��� 1���� �����Ѵ�. �׷��� �θ��ڽ��� �ε������� ���� �������� ���ԵǾ� ����� ���ϱ� ����

	// �Ʒ� while �� �����ϸ鼭 ���� INSERT�� data�� ��ġ�� idx�� ���� (���� �����ϴ°� �ƴ�. ���� ��ġ�� �����ϴ°�)
	while (idx != 1) // root (�ֻ���) �� �����Ҷ� ����
	{
		// �θ�� �켱���� ��
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0) // �θ𺸴� �켱������ ���ٸ�
		{
			// �θ� �������
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];

			// idx �� �θ��� idx�� �̵�
			idx = GET_PARENT_IDX(idx);
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
HData heap_delete(Heap *ph)
{
	// root�� ���ֱ�
	HData rootData = ph->heapArr[ROOTIDX]; // �ε��� 1���� ��Ʈ ���, �̸� �����ϰ� ����

	// ������ ��尡 �ڸ����� ��ġ idx �� �����ؾ� �Ѵ� .
	// idx�� �����ɶ����� ������ ����� data�� ������ ���´�.

	HData lastElem = ph->heapArr[ph->numData];
	// ����������� ���� �����س���

	int idx = ROOTIDX; // ������ ��尡 �ϴ� root �ڸ��� ���� �ȴ�.
	int childIdx;

	while (childIdx = getHighPriority(ph, idx))
	// �� ���Կ����� ��ü�� ������� ����. ������ �� ��ü�� �������.
	// 0�ϰ�� false �̹Ƿ� while�� Ÿ�� �ʴ´�. ��, getHighPriority �Լ��� return 0; �� �ϴ� ���� �ڽĳ�尡 ���� ����̹Ƿ�, if������ break ���� �ʴ´ٸ� �ڽĳ�尡 ���� ������ �����Ѵٴ� �ǹ��̴�. 1�� idx, �� ROOTIDX���� �������� �������鼭 ���ǿ� �´� ���� �����ϴ� idx�� ã�´�.
	{
		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[idx] = ph->heapArr[childIdx];

		idx = childIdx;
	}

	ph->heapArr[idx] = lastElem;
	// ph->heapArr[ph->numData] = NULL;
	ph->numData--;

	return rootData;
}

void HeapSort(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		heap_insert(g_hp, arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		arr[i] = heap_delete(g_hp);
	}
	// �׳� insert�ϰ� �״�� delete�ϸ� arr�� ���ĵ� ������� �����Ͱ� ���ð���.
}
