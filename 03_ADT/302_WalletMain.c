#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 
#include "301_Wallet.h"

/*

*/

int main() {

	Wallet myWallet; // 지갑 생성

	Wallet *p = &myWallet; 
	//ㅇㅋ?

	wlt_init(&myWallet); //지갑 초기화 
	// p = &myWallet
	wlt_put_coin(&myWallet, 2); // 동전삽입: 500 x 2개
	wlt_put_bill(&myWallet, 1); // 지폐삽입 : 1000원 x 1개
	printf("잔액 : %d\n", wlt_balance(&myWallet)); // 2000원 

	wlt_put_coin(&myWallet, 3); // 동전삽입: 500 x 2개
	wlt_put_bill(&myWallet, 4); // 지폐삽입 : 1000원 x 1개 
	printf("잔액 : %d\n", wlt_balance(&myWallet)); // 7500원 

	wlt_take_coin(&myWallet, 4); // 동전 추출 
	wlt_take_bill(&myWallet, 2); // 지폐 추출
	printf("잔액 : %d\n", wlt_balance(&myWallet)); //잔액 3500원 

	wlt_take_coin(&myWallet, 1); // 추출 실패
	wlt_take_bill(&myWallet, 10); // 추출 실패
	printf("잔액 : %d\n", wlt_balance(&myWallet));

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}