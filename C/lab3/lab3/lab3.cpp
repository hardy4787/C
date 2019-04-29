#include "stdafx.h"
#include "conio.h"
#include "locale.h"

void ExerciseOne();
void ExerciseTwo();
void Instruction();
void InstructionEx1();
void InstructionEx2();

int main(){
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
	int num;
	printf("������� ����� �������� �������� �������� ������: ");
	if (scanf_s("%d", &num)) {
		if (num >= -3 && 0 >= num) {
			printf("����� [%d] ������ � �������� �� -3 �� 0", num);
		}
		else if (num >= 3 && 6 >= num) {
			printf("����� [%d] ������ � �������� �� 3 �� 6", num);
		}
		else {
			printf("����� [%d] �� ������ �� � ���� �� ����������, � ������\n\t�� -3 �� 0\n\t�\n\t�� 3 �� 6", num);
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
	int mon;
	printf("������� ����� ������: ");
	scanf_s("%d", &mon);
	switch (mon) {
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
		printf("������� ������ �� ����������.\n��������� ������� ����������.");
		_getch();
		InstructionEx2();
		break;
	}
	if (mon == 1 || mon == 2 || mon == 12) {
		printf(" - ����");
	}
	else if(mon == 3 || mon == 4 || mon == 5) {
		printf(" - �����");
	}
	else if (mon == 6 || mon == 7 || mon == 8) {
		printf(" - ����");
	}
	else{
		printf(" - �����");
	}
	InstructionEx2();
	printf("\n");
}

void Instruction(){
	printf("\t������������ ������ �3\n"
		"1)�������� ��������� ����� � ��������\n"
		"2)����������� ������� ���� �� ����� ������\n"
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


