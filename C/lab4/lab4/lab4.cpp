#include "stdafx.h"
#include "conio.h"
#include "locale.h"

void ExerciseOne();
void ExerciseTwo();
void Instruction();
void InstructionEx1();
void InstructionEx2();

int main() {
	int n;
	setlocale(LC_ALL, "RUS");
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
	int num, ft=1, i;
	printf("������� �����: ");
	if (scanf_s("%d", &num)) {
		if (num >= 1){
			for (i = 2;i <= num;i++) {
				ft = ft*i;
			}
			printf("��������� [%d] �����: %d", num, ft);
		}
		else if (num == 0) {
			printf("��������� [%d] �����: 1", num);
		}
		else {
			printf("������: ���������� �������������� ����� �� ����������.");
		}
	}
	else {
		printf("������: ��������� ������ �����.");
	}
	InstructionEx1();
	printf("\n");
	_getch();
}

void ExerciseTwo() {
	int numb, i = 1, min;
	printf("������� %d-��: ", i);
	if (scanf_s("%d", &numb)) {
		min = numb;
		i++;
	}
	else {
		printf("������: ������� �����.\n\n");
		rewind(stdin);
		ExerciseTwo();
	}
	do{
		printf("������� %d-��: ",i);
		if (scanf_s("%d", &numb)) {
			if (numb < min) {
				min = numb;
			}
			i++;
		}
		else {
			printf("������: ������� �����.\n\n");
			rewind(stdin);
			ExerciseTwo();
		}
	}while (i <= 5);
	printf("\n�����������: %d", min);
	InstructionEx2();
	printf("\n");
}

void Instruction() {
	printf("\t������������ ������ �4\n"
		"1)��������� ��������� �����\n"
		"2)����������� ������������ ����� �� 5-��\n"
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


