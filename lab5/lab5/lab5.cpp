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
	int *num, size, i, j, ct=0;
	printf("������� ������ �������: ");
	if (!scanf_s("%d", &size)) {
		printf("\n������: ������� �����.\n");
		rewind(stdin);
		ExerciseOne();
	}
	if (size > 0) {
		if (!(num = (int*)malloc(sizeof(int)*size))) {
			printf("\n������: �������� ������.\n");
		}
		for (j = 0;j <= size - 1;j++) {
			printf("������� [%d]-�� �����: ", j + 1);
			scanf_s("%d", &num[j]);
		}
		for (j = 0;j <= size - 1;j++) {
			for (i = j + 1;i <= size - 1;i++) {
				if ((num[j] == num[i])) {
					printf("� ������� ������������ �������� � ���������� ���������.");
					InstructionEx1();
				}
			}
		}
		printf("� ������ ������� ��� ��������� � ����������� ����������.");
	}
	else {
		printf("������: ������� ������������ �������.");
	}
	InstructionEx1();
	printf("\n");
	_getch();
}

void ExerciseTwo() {
	int **mtx,*ser, n, i,j;
	printf("������� ������ ���������� �������: ");
	if (!scanf_s("%d", &n)) {
		printf("\n������: ������� �����.\n");
		rewind(stdin);
		ExerciseTwo();
	}
	printf("\n");
	if (!(mtx = (int**)malloc(sizeof(int*)*n))) {
		printf("\n������: �������� ������.\n");
	}
	if (!(ser = (int*)malloc(sizeof(int)*n))) {
		printf("\n������: �������� ������.\n");
	}
	for (i = 0;i <= (n - 1);i++) {
		if (!(mtx[i] = (int*)malloc(sizeof(int)*n))) {
			printf("\n������: �������� ������.\n");
		}
		for (j = 0;j <= (n - 1);j++) {
			printf("mtx[%d][%d] = ", i, j);
			scanf_s("%d", &mtx[i][j]);
		}
	}
	printf("\n\n");
	for (i = 0;i <= (n - 1);i++) {
		for (j = 0;j <= (n - 1);j++) {
			printf("%3d", mtx[i][j]);
		//	if(ser)
		//	ser[i]=ser[i]+mtx[i][j]
		}
		printf("\n");
	}
	for (i = 0;i <= (n-1);i++) {
		ser[i] = 0;
		for (j = 0;j <= (n - 1);j++) {
			ser[i] = ser[i] + mtx[j][i];
		}
		printf("\n������� �������������� %d-�� ������� = %d", i+1, ser[i]/n);
	}
	InstructionEx2();
	printf("\n");
}

void Instruction() {
	printf("\t������������ ������ �3\n"
		"1)�������� ������� ���������� ��������� � �������.\n"
		"2)���������� �������� ��������������� �� �������� �������\n"
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


