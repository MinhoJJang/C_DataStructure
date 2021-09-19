#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺��� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 

/*
	�Լ� ������ (function pointer)
	'�Լ��̸�' �� �� '������' 
*/

void fnPlus(int a, int b) {
	printf("����: %d + %d = %d\n", a, b, a + b);
}

void fnMinus(int a, int b)
{
	printf("����: %d - %d = %d\n", a, b, a - b);
}

void fnMul(int a, int b)
{
	printf("����: %d * %d = %d\n", a, b, a * b);
}

void fnDiv(int a, int b)
{
	printf("������: %d / %d = %d\n", a, b, a / b);
}

void doAction(int a, int b, void(*fnOp)(int, int)) {
	//�Լ� ���� �Լ�
	(*fnOp)(a, b);
}

//void(*fnOp)(int, int) => fnAction(int, int)�� ���� ���� ��찡 ����
typedef void fnAction(int, int); //fnAction�� �Լ��̸��� �ƴ϶� '�Լ������� Ÿ��' �̴�! ����Ƴ�!!!�Ф�

void doAction2(int a, int b, fnAction *fnOp) {
	(*fnOp)(a, b);
}

int main() {

	{
		fnPlus(10, 20);

		printf("fnPlus -> %p\n", fnPlus);
		//�Լ��̸��� �� �Լ�������

		//�Լ��������� '����' �� �� 'ȣ��' �����̴�.
		// ���������� * ����ؼ� ȣ�� ���� 

		(*fnPlus)(30, 40); //ȣ��

		// �Լ� ������ Ÿ�� ���� ���� ����
		// int *p;   <-- int �� ���� ������
		// void �����ϰ� (int, int) �Ű����� �޴� �Լ��� ���� �Լ� ������?
		void(*fnOp)(int, int); // <-- fnOp ��� '�Լ� ������ ���� ����'

		// �����ͺ��� <- ���� ���� 
		// �Լ��� �����Ҽ� �ִ�!!
		fnOp = (*fnPlus); 
		//(*fnPlus)=fnPlus
		//���� fnOp�� �Լ�ó�� ��� ����
		(*fnOp)(70, 100);

		printf("\n");
		{
			// �Լ��������� ����.
			// '����'�� ���߿� ���� ���� (late-binding)

			int op;
			printf("���۹�ȣ�� �Է��ϼ���(0:+ 1:- 2:* 3:/): ");
			scanf("%d", &op);

			int a = 30, b = 10;
			int i = 0;
			for (i = 0; i < 5; i++)
			{
				if (op == 0)
					fnPlus(a, b);     //< --�� ������ �����ڵ�� 100 % fnPlus �� ȣ���Ѵ�!
				else if (op == 1)
					fnMinus(a, b);    //< --�� ������ �����ڵ�� 100 % fnMinus ��!
				else if (op == 2)
					fnMul(a, b);      //
				else if (op == 3)
					fnDiv(a, b);
			}

			// �� �̹� �������Ҷ� �ڵ�� ���õ� 'Ư��'�Լ��� ����ǵ��� ���ε� �ȴ�.  --> Early Binding �̶� ��
			// �� ��ȯ������ ���ǹ��� ���� ������ �Լ� ȣ���� ȣ���ؾ� �ϴ�, ���ǹ��⺻ �ε尡 ŭ
			// �Ź� �ݺ��ϴ°� �ð��ʰ��� ������ ŭ.

			// �ݸ�
			// �Լ������� ���� 
			void(*fnAction)(int, int);

			// �Լ������� �迭
			void(*fnOpArr[])(int, int) = {fnPlus, fnMinus, fnMul, fnDiv};

			fnAction = fnOpArr[op]; //op: 0~3

			printf("\n");
			for (i = 0; i < 5; i++) {
				(*fnAction)(a, b);

				// �� fnAction �� ����.. �׷��� ������ ������ ������ �������� �𸥴� (�� ���ε��� �Ǿ� ���� �ʴ�)
				// ���� �ؾ� ���߿� ������ �����ȴ�.   late-binding

				// ����: ���ǹ��� ���� �ε尡 ����.
				// �������!!
			}
		}

		// �Լ� �����͵� �����ʹ�!  
		// �Ű������� �Ѱ��ټ���, ���ϰ����� ��������
		// �迭 ���Ұ� �ɼ��� �ִ�!!

		printf("\n");
		{
			doAction(333, 444, fnPlus);
			doAction(333, 444, fnMinus);
			doAction2(333, 444, fnMul);
			doAction2(333, 444, fnDiv);
		}
	}

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}