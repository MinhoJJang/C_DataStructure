#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*

*/

int main() {

	// time() �Լ�
	{
		time_t start, end;
		printf("time() ��������\n");

		start = time(NULL); // ���۽ð�, ����ð� ����

		// �����ϰ��� �ϴ� �����ڵ� 
		/*for (int i = 0; i < 5; i++) {
			printf("%d ", i);
			_sleep(1000);
		}
		printf("\n");
		*/

		/*{

			int x, y, z;
			int Test, t;

			scanf("%d", &Test);

			int ans[100] = { 0 };

			for (t = 0; t < Test; t++) {

				scanf("%d%d", &x, &y);

				z = y - x;
				int n;

				for (n = 0; ; n++)
				{
					if (z - n * n <= 0) {
						break;
					}
				}

				if (z > n*n - n) {
					ans[t] = 2 * n - 1;
				}
				else {
					ans[t] = 2 * n - 2;
				}

				x = 0;
				y = 0;
			}

			for (t = 0; t < Test; t++) {
				printf("%d\n", ans[t]);
			}

		}*/

		end = time(NULL); // ����ð� 

		double result = (double)(end - start); //����ð�
		printf("%f s\n", result);
	}



	//�ð����� : clock() ���
	{
		clock_t start, end;

		start = clock(); //����, ����ð� ����

		// �����ϰ��� �ϴ� �����ڵ� 
		for (int i = 0; i < 5; i++) {
			printf("%d ", i);
			_sleep(1000);
		}
		printf("\n");

		end = clock(); // ���� 
		long result = end - start;
		printf("%ld ms\n", result);
		
	}

	//�ð�: Time Complexity
	//�뷮: Space Complexity

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}