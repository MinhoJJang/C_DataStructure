#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 

/*
https://docs.google.com/presentation/d/1gta0SbUOW4H4EAyt6cvTs-ReGZ_RLdzoiY5-g-dpZkc/edit#slide=id.g505982888d_0_318

26p

======
Inorder
======
left->center->right

center을 기준으로 트리를 나눈다.

5의 left 4, 4의 left 3. 3의 left가 없으므로 3이 먼저 나옴
3나오고 center 4나옴 .
이후 0을 기준으로 left가 8, 8의 left는 공백이고 8은 7을 기준으로 center이므로 

3-4-8-7-0-1-5-9-2

======
Preorder 
======
center-left-right

5가 center.
4가 5기준 left이며 center.
3이 4기준 left.
이후 4기준 right 0.
0을 center로 8이 left, 8은 center로 7이 right.
그다음에 0기준 right 1.

5-4-3-0-8-7-1-2-9

=======
Postorder
=======
left-right-center

가장 left가 3.
그다음 4의 right가 0이고 0을 center로 left가 8이고 8을 center로 right가 7.

즉
3-7-8-1-0-4-9-2-5
*/

