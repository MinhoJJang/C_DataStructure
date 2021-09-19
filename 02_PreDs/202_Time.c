#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..동적메모리, 난수, 문자열 변환
#include <string.h> //strcpy.. 문자열함수. memcpy.. 메모리블럭 함수
#include <conio.h> // _getch, putch ... MS기반 C 비표준 함수
#include <time.h> // clock .. 시간, 날짜 함수
#pragma warning(disable:4996) // scnaf() 등 전통 c함수중 버퍼문제. 
#pragma warning(disable:4477) // unsigned <--> signed 관련 warning 무시 

/*

*/

int main() {

	// time() 함수
	{
		time_t start, end;
		printf("time() 측정시작\n");

		start = time(NULL); // 시작시간, 현재시간 측정

		// 측정하고자 하는 수행코드 
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

		end = time(NULL); // 종료시간 

		double result = (double)(end - start); //경과시간
		printf("%f s\n", result);
	}



	//시간측정 : clock() 사용
	{
		clock_t start, end;

		start = clock(); //시작, 현재시간 측정

		// 측정하고자 하는 수행코드 
		for (int i = 0; i < 5; i++) {
			printf("%d ", i);
			_sleep(1000);
		}
		printf("\n");

		end = clock(); // 종료 
		long result = end - start;
		printf("%ld ms\n", result);
		
	}

	//시간: Time Complexity
	//용량: Space Complexity

	printf("\n아무키나 입력하면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
}