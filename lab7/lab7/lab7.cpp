#include "stdafx.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "stdlib.h"
#include "Windows.h"
#include "stdio.h"
#include "time.h"

void ExerciseOne();
void Instruction();
void InstructionEx1();
void error();

int main() {
	int n;
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Instruction();
	scanf_s("%d", &n);
	switch (n) {
	case 1:
		system("cls");
		ExerciseOne();
		break;
	default:
		system("cls");
		printf("������: ������� ������ ���� ���. ������� 1 ��� 2.\n");
		main();
	}
}

void ExerciseOne() {
	int i,//����� �����
		j,//����� ��������
		n,//������� ����� ����� � �������
		m,//������� ����� �������� � �������
		**arr,//��������� �� ��������� ������
		*swap,//����� ����������
		a,//��������������� ��� ������� �� ��������
		l;//��������������� ��� �������� �� ���������� ��������� � ������
	srand(time(NULL));
	printf("������� ������ ���������� �������:");
	printf("\n���������� ����� = ");
	scanf_s("%d", &n);
	printf("���������� �������� = ");
	scanf_s("%d", &m);
	if (!(arr = (int**)malloc(n * sizeof(int*)))) {
		printf("��� ������ ������� �� ������� ������!\n");
		system("pause");
		return 1;
	}
	/*���������� ������� ������� */
	printf("\n������� �������� ��������� �������: ");
	printf("\n");
	for (i = 0;i < n;i++) {
		if (!(arr[i] = (int*)malloc(m * sizeof(int)))) {
			printf("��� ������ ������� �� ������� ������!\n");
			system("pause");
			return 1;
		}
		for (j = 0;j < m;j++) {
		de:
			printf("arr[%d][%d]=", i, j);
			if (scanf_s("%d", &arr[i][j])) {
				for (l = i - 1; l >= 0; l--) { //�������� �� ���������� ��������� � ������
					if (arr[i][j] == arr[l][j]) {
						printf("�� ����� ������������� �������!\n");
						goto de;
					}
				}
			}
			else {
				error();
				goto de;
			}
		}
	}
	printf("\n");
	/*������ �������*/
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {//������ ������� i-�� ������ �������
			printf("%3d", arr[i][j]);
		}
		printf("\n");//������� � ������ ����� ������
	}
	//���������� ����� ���������� �������
	for (i = 0;i < m;i++) {
		for (j = 0; j < (n - 1);) {
			if (arr[i][j] > arr[i][j + 1]) {
				for (a = 0; a < (n - 1);a++) {
					if (arr[i][a] > arr[i][a + 1]) {
						swap = arr[i][a];
						arr[i][a] = arr[i][a + 1];
						arr[i][a + 1] = swap;
					}
				}
				j = 0;
			}
			else {
				j++;
			}
		}
	}
	/*������ �������*/
	printf("\n ��������������� ������: \n");
	for (i = 0;i < m;++i) {
		for (j = 0; j < n; ++j) {
			printf_s("%3d", arr[i][j]);
		}
		printf("\n");
	}
	free(arr);
	InstructionEx1();
	printf("\n");
	_getch();
}

void Instruction() {
	printf("\t������������ ������ �7\n"
		"��������� ������� ����������� �� ����������� ��������,\n"
		"������������ � ������� ���������� ������� �������� n x m.\n"
		"������� ������ �� �����. ������ ������ �������� �� ����� �����.\n"
		"�������� n x m, � ����� �������� ��������� ������� �������� ������������� � ����������.\n"
		"�������� � �������� ������� � �� ������ �����������.\n"
		"1)������� � ���������: ");
}

void InstructionEx1() {
	int n;
	printf("\n1)��������� �������\n"
		"2)����� � ����\n"
		"3)��������� ���������\n");
	do {
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			system("cls");
			ExerciseOne();
			break;
		case 2:
			system("cls");
			rewind(stdin);
			main();
			break;
		case 3:
			exit(0);
		}
	} while (n != 1 || n != 2 || n != 3);
}

void error() {
	printf_s("������ �����!\n");
	rewind(stdin);
}
