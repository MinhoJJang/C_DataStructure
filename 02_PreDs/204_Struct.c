#include <stdio.h>
#include <stdlib.h> // malloc, rand, atoi ..�����޸�, ����, ���ڿ� ��ȯ
#include <string.h> //strcpy.. ���ڿ��Լ�. memcpy.. �޸𸮺� �Լ�
#include <conio.h> // _getch, putch ... MS��� C ��ǥ�� �Լ�
#include <time.h> // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996) // scnaf() �� ���� c�Լ��� ���۹���. 
#pragma warning(disable:4477) // unsigned <--> signed ���� warning ���� 


/*
	����ü (struct)
		�������� �����͵� (���) �� ������ ����� ���� �ڷ���


	�л��� ������
		-�й� : char[]
		-�̸� : char[]
		-���� : unsigned char  (0 ~ 255)
		-�г� : unsigned char
		-���� : 'M', 'F'  char
		-Ű : 173.4  float
		...
*/

struct point {
	int x; //��� ����
	int y; //��� ���� 
	//point��� ����ü�� �����ϰ��ִ� ��� ���� int Ÿ�� x,y
}; //����ü ����

struct person
{
	char name[20]; // �̸�
	int age;				// ����
	double weight;	// ������
};

typedef struct person PS; //struct person = PS


typedef struct _person {
	char name[20]; // �̸�
	int age;				// ����
	double weight;	// ������
} Person; 
//struct _person �̶�� ����ü�� ������ Person�̶�� �θ��ڴٴ� �ǹ�
// 30~37�� ������ ��ģ��. 


int main() {

	struct point p1;



	// ��������� ( . ) ����ؼ� ����ü ��� ���.
	p1.x = 100; //(p1�� x���� 100�� �����Ѵ�)
	p1.y = 200;

	printf("p1 => (%d,%d)\n", p1.x, p1.y);

	struct person p2; 
	// = PS p2; 

	p2.age = 32;
	p2.weight = 74.3;
	strcpy(p2.name, "ȫ�浿");
	//p2.name�������� ���� ���ڿ��� �����Ҽ� �����ϱ� string copy ����ؼ� ����

	printf("�̸� : %s , ���� : %d�� , ������ : %.1fkg\n", p2.name, p2.age, p2.weight);

	PS p3;
	Person p4;
	Person p5 = { "LOKI", 100, 87.567 }; 
	//����� ���ÿ� �ʱ�ȭ ���� 
	printf("�̸� : %s , ���� : %d�� , ������ : %.1fkg\n", p5.name, p5.age, p5.weight);

	// ����ü�� ���� ������

	Person *ptr = &p5;

	printf("�̸� : %s , ���� : %d�� , ������ : %.1fkg\n", ptr->name, ptr->age, ptr->weight); 
	//or
	printf("�̸� : %s , ���� : %d�� , ������ : %.1fkg\n", (*ptr).name, (*ptr).age, (*ptr).weight);

	printf("\n�ƹ�Ű�� �Է��ϸ� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;
}

//��������

// �Է��� �л����� �Է��ϰ�, �л�����ŭ�� �л��� ������ ��� ����ü�� ����� �����͸� ���� ���� x�� �Է¹޾Ƽ� x��° �л��� ������ �����ϰ� �Ϸ���...?