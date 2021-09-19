#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#include "Heap.h"

#define SUCCESS 1
#define FAIL 0

// -----------------------------------------
// 부모노드 인덱스 
int getParentIdx(int idx) {
	return idx / 2;
}

// left 자식노드 인덱스 
int getLeftIdx(int idx) {
	return idx * 2;
}

// right 자식노드 인덱스 
int getRightIdx(int idx) {
	return idx * 2 + 1;
}

// idx의 자식들 중 우선순위가 높은 자식의 index값 리턴 --> delete 에 사용 
int getHighPriority(Heap *ph, int idx)
{
	// 자식노드가 없다면 0리턴 
	if (getLeftIdx(idx) > ph->numData) return 0;

	// 자식노드가 1개라면 (왼쪽 노드가 유일)
	if (getLeftIdx(idx) == ph->numData) return getLeftIdx(idx);

	// 우선순위 
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
	//라고 해도 되지만 우리는 comp함수가 있으니 그걸 쓰자
	
	return idx;

}

// 힙 초기화
void heap_init(Heap *ph, fnPriorityComp pc) {
	ph->numData = 0; // 데이터(노드)개수 0
	ph->comp = pc; 
	// fnPriority...는 이러한 타입의 함수가 있다..는 것을 알려주는것이고 DataPriorityComp 는 '그러한 타입'의 함수. 
}

// 힙이 비어있는지? 
int heap_is_empty(Heap *ph) {
	if (ph->numData == 0) return SUCCESS;
	return FAIL;
}

// 힙에 데이터 추가 insert
void heap_insert(Heap *ph, HData data) {

	// 새로 insert되는 데이터는 맨 끝에서 시작 
	int idx = ph->numData + 1;
	// ph->numData 는 현재있는 노드개수이므로 새로 들어가는 값인 idx는 노드개수+1번째에 들어가야한다. 
	// 또한 배열 인덱스는 배열이 0부터 시작하는 것과는 다르게 1부터 시작한다. 그래야 부모자식의 인덱스값이 서로 연관성을 갖게되어 계산이 편리하기 때문

	// 아래 while 문 수행하면서 새로 INSERT된 data가 위치할 idx를 결정 (값을 결정하는게 아님. 값의 위치를 결정하는것)
	while (idx != 1) // root (최상위) 에 도달할때 까지
	{
		// 부모와 우선순위 비교 
		if (ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0) // 부모보다 우선순위가 높다면
		{
			// 부모를 끌어내리기
			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];

			// idx 를 부모의 idx로 이동 
			idx = getParentIdx(idx);

		}
		// 새로 넣은 값의 번호가 idx임 
		else // 부모보다 우선순위가 낮거나 같다.. 여기서 while 멈춰야함
		{
			break;
		}
	}

	// idx가 결정된 그곳이 새로 INSERT된 data가 들어갈 위치 

	ph->heapArr[idx] = data;
	ph->numData++;

}

// 힙에 데이터 빼기 delete. 삭제는 root에서 발생 
int heap_delete(Heap *ph) {

	// root값 없애기 
	HData rootData = ph->heapArr[1]; // 인덱스 1번이 루트 노드, 이를 제거하고 리턴 

	// 마지막 노드가 자리잡을 위치 idx 를 결정해야 한다 .
	// idx가 결정될때까지 마지막 노드의 data는 보관해 놓는다. 

	HData lastElem = ph->heapArr[ph->numData];
	// 마지막노드의 값을 저장해놓기 

	int idx = 1; // 마지막 노드가 일단 root 자리에 오게 된다. 
	int childIdx; 

	//// 일단, 자식노드중 우선순위 높은거 선택
	//childIdx = getHighPriority(ph, 1);

	//	// 아래 while 문은 결국 idx 값을 결정하기 위함.
	//	while (ph->comp(ph->heapArr[childIdx], ph->heapArr[idx]) < 0) {
	//		// 선택된 자식과, 아래에서 올라온 마지막 노드와 우선순위 비교. 
	//		// 만약 자식의 우선순위가 같거나 낮다면 while 종료

	//		ph->heapArr[idx] = ph->heapArr[childIdx];
	//		// 자식의 우선순위가 더 크다면,  그 자식이 부모의 자리로 교체

	//		idx = childIdx;
	//		// 다음 비교를 위해 마지막 노드 idx를 좀전의 자식위치로 내리기
	//	
	//		if (ph->numData < (idx * 2)) {
	//			break;
	//		} // 만약 자식이 하나도 없다면 0이 리턴되어 while 문 종료 
	//		  // while문에서 어차피 처리되지 않나? 넣어야하는 조건식인가?

	//		childIdx = getHighPriority(ph, idx);
	//		// 선택된 자식노드 인덱스값 다시 정하기 
	//	}

	while (childIdx = getHighPriority(ph, idx)) 
		// 저 대입연산자 자체가 결과값이 있음. 대입한 값 자체가 결과값임. 
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


	