#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 

#include "301_Wallet.h"

#define FAIL 0
#define SUCCESS 1

void wlt_init(Wallet *p) {
	printf("지갑을 초기화 합니다\n");
	p->bill1000 = 0;
	p->coin500 = 0;
}//지갑의 초기화

void wlt_put_coin(Wallet *p, int coinNum) {
	p->coin500 += coinNum;
	printf("동전 %d 개 삽입되어 %d개가 되었습니다.\n", coinNum, p->coin500);
}//동전 삽입

int wlt_take_coin(Wallet *p, int coinNum) {
	if (p->coin500 < coinNum) {
		printf("동전개수가 부족하여 %d 개를 추출할 수 없습니다\n", coinNum);
		return FAIL;
	}

	p->coin500 -= coinNum;
	printf("동전 %d 개 추출되어 %d 개가 되었습니다\n", coinNum, p->coin500);
	return SUCCESS;
}//동전 추출

void wlt_put_bill(Wallet *p, int billNum) {
	p->bill1000 += billNum;
	printf("지폐 %d 개 삽입되어 %d개가 되었습니다.\n", billNum, p->bill1000);
}//지폐 삽입

int wlt_take_bill(Wallet *p, int billNum) {
	if (p->bill1000 < billNum) {
		printf("지폐개수가 부족하여 %d 개를 추출할 수 없습니다\n", billNum);
		return FAIL;
	}

	p->bill1000 -= billNum;
	printf("지폐 %d 개 추출되어 %d 개가 되었습니다\n", billNum, p->bill1000);
	return SUCCESS;

}//지폐 추출

int wlt_balance(Wallet *p) {
	return p->coin500 * 500 + p->bill1000 * 1000;
}//지갑내 잔액 확인 