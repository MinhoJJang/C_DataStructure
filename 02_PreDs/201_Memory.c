#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*
	free()
*	malloc(), 
*   calloc(), realloc()
*
*   memcpy(), memset()
*/

int main() {

	// ���� �޸� �Ҵ�: Dynamic memory allocation
	{
		int len = 100000; //�鸸 ����Ʈ�� �޸𸮸� �Ҵ�
		int *arr = (int*)malloc(len); 
		//(int*)�� ��������ȯ �ϴ� ������??
		//memory-allocation
		//malloc(byte_size) �޸𸮺��� �Ҵ�ް�, �ּҸ� ����
		//malloc�� void pointer �����̹Ƿ� int* �� �ٲ��ش�.
		printf("arr[0] : %d\n", arr[0]);

		// �޸� �Ҵ� �޾����� �ʱ�ȭ �����ִ°��� ����. 
		// memset(�ּ�, �ʱ�ȭ�� ��, ����Ʈ��)
		memset(arr, 0, len); // arr�������� len ��ŭ�� ����Ʈ�� 0���� �ʱ�ȭ
		printf("arr[0] : %d\n", arr[0]);

		// �����޸𸮴� ����� �Ŀ� �ݵ�� free (�Ҵ�����, �ݳ�) �ؾ��� 
		// ��񵿾� �����Ŵϱ�..
		free(arr);

		// free(arr);  ���ȿ��� ����ϴ� �����Ҵ�� �����ʹ� �ؾ������ ã���������� ����������.
		// �޸𸮴� ������ �����ε� �������ʰ� �ݳ��� ���ϰ� ��ġ�ϸ� �޸� �����..
		// �ڡ� �޸� ���� Memory Leak �߻� ����!!!! �ڡ�
	}

	printf("\n"); 

	{
		//realloc() : re-allocation(). �޸� ���Ҵ�
		// ������ �޸� �Ҵ�� �͵��� ������ �����Ҵ� �޾Ƽ� ���뺹��
		// ���� �޸𸮿� ���� �迭 Ȯ�� ����.

		int *arr1 = (int*)malloc(sizeof(int) * 3);
		//12byte
		arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
		//���� 
		arr1[3] = 40; // (���� �Ҵ���� �޸𸮴� arr1[2] �����ε� arr1[3] �־������ ������)

		printf("%d %d %d\n", arr1[0], arr1[1], arr1[2]);

		// �����޸� ���Ҵ� (Ȯ��, ���)
		//  ������ arr1 �� �Ҵ�� ������ ���� �˴ϴ�. (���� free() ��Ű�� �ʾƵ� ��)
		// �������� �̻簣��~
		arr1 = (int*)realloc(arr1, sizeof(int) * 5);

		arr1[3] = 40; //�����Ͱ� �߰��� �ֱ� 

		printf("%d %d %d %d\n", arr1[0], arr1[1], arr1[2], arr1[3]);

		free(arr1);
	}	

	printf("\n�޸� �������ϸ� ���� - �ƹ�Ű�� ������ �����մϴ�\n");
	//�����-�޸� �������Ϸ�-���� 
	_getch();
	{
		int len = 1000000;
		int *arr;

		// �޸� ���� ����
		for (int i = 0; i < 10; i++) {
			arr = (int*)malloc(sizeof(int)*len); //'4�鸸 ����Ʈ' �� '10���ݺ�' �ؼ� �ٽ� �Ҵ�
			//�̷��� ����� �������ִ� 4�鸸 �����Ͱ� ���� ������..
			//�� free(arr);�� for�� ���� �־����
			_sleep(5000); //delay ms ���� 1000ms = 1sec
			 //5�ʵڿ� free(arr)�ϰ�
			free(arr);
			_sleep(5000); //�ٽ� 5�ʵڿ� �Ҵ�ް�
		}
		//free(arr); // �޸� ���� 
		//�޸� �������Ϸ� �������� ��� �ö󰡴ٰ� for�� ����� �ѹ� �ݳ���. �ᱹ 9���� �޸𸮴� �ݳ��� ���� ����.. �� �޸𸮸� ����ϴ� �����Ͱ� ���� ������ 
	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}