#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*
https://docs.google.com/presentation/d/1gta0SbUOW4H4EAyt6cvTs-ReGZ_RLdzoiY5-g-dpZkc/edit#slide=id.g505982888d_0_318

26p

======
Inorder
======
left->center->right

center�� �������� Ʈ���� ������.

5�� left 4, 4�� left 3. 3�� left�� �����Ƿ� 3�� ���� ����
3������ center 4���� .
���� 0�� �������� left�� 8, 8�� left�� �����̰� 8�� 7�� �������� center�̹Ƿ� 

3-4-8-7-0-1-5-9-2

======
Preorder 
======
center-left-right

5�� center.
4�� 5���� left�̸� center.
3�� 4���� left.
���� 4���� right 0.
0�� center�� 8�� left, 8�� center�� 7�� right.
�״����� 0���� right 1.

5-4-3-0-8-7-1-2-9

=======
Postorder
=======
left-right-center

���� left�� 3.
�״��� 4�� right�� 0�̰� 0�� center�� left�� 8�̰� 8�� center�� right�� 7.

��
3-7-8-1-0-4-9-2-5
*/

