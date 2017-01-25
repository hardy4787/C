#include "stdafx.h"
#include "conio.h"
#include "locale.h"
#include "string.h"
#include "stdlib.h"
#include "Windows.h"
#include "stdio.h"

void ExerciseOne();
void ExerciseTwo();
void Instruction();
void InstructionEx1();
void InstructionEx2();

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
	case 2:
		system("cls");
		ExerciseTwo();
		break;
	default:
		system("cls");
		printf("������: ������� ������ ���� ���. ������� 1 ��� 2.\n");
		main();
	}
}

void ExerciseOne() {
	int num; /*����� ������*/
	printf	("������� ����� ������: ");
	if (scanf_s("%d", &num)) {
		printf("�������� �����: ");
		switch (num)
		{
		case 1:
			printf("������");
			break;
		case 2:
			printf("�������");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("������");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("����");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("������");
			break;
		case 9:
			printf("��������");
			break;
		case 10:
			printf("�������");
			break;
		case 11:
			printf("������");
			break;
		case 12:
			printf("�������");
			break;
		default:
			printf("�� ��������� ����� ������.");
			break;
		}
	}
	else {
		printf("������: ������� �����");
	}
	InstructionEx1();
	printf("\n");
	_getch();
}

void ExerciseTwo() {
	char *chr; /*�����*/
	int err = 0, /* ���� 1 �� �� ���������*/
		lengh; /*������ �����*/
	rewind(stdin);
	chr = (char*)malloc(sizeof(chr));
	printf("������� �����: ");
	fgets(chr, 100, stdin);
	lengh = strlen(chr);
	for (int i = 0; i <= lengh - 2 && err == 0; i++) {
		if (toupper(chr[i]) != toupper(chr[lengh - i - 2])) {
			err = 1;
		}
	}
	if (err == 0) {
		printf("YES");
	}
	else { 
		printf("NO"); 
	}
	InstructionEx2();
	printf("\n");
}

void Instruction() {
	printf("\t������������ ������ �8\n"
		"1)����� ������ �� ������\n"
		"2)��������� ��� ���\n"
		"�������� ���������: ");
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

void InstructionEx2() {
	int n;
	printf("\n1)��������� �������\n"
		"2)����� � ����\n"
		"3)��������� ���������\n");
	do {
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			system("cls");
			ExerciseTwo();
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


