#include "stdafx.h" 
#include "Windows.h" 
#include "stdio.h" 
#include "conio.h" 
#include "locale.h" 
#include "string.h" 

void Instruction();

typedef struct Word {
	int plum;
	char *strk;
}Word;

int main(int argc, char *argv[])
{
	Word *words = NULL;
	FILE *fp,
		*lpout,//�������� ���� 
		*litf;
	char *str = NULL,//��������� �� ������; 
		*lit,//��������� �� ������ � �������; 
		*s = NULL,//��������� �� �����������; 
		*lol = NULL,
		ch,
		*pm = NULL,
		*nun;//��������������� ��������� ��� ������� "strtok_s"; 
	int SIZE = 200,//������������ ������ ������; 
		count = 0,//������� ����������; 
		k,//������� �����; 
		j,//������� �����; 
		i = 0,//������� �����;
		max = 0,
		n;//��������������� ������;
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do{
		Instruction();
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			system("cls");
			ExerciseOne();
			break;
		}
	}while (n != 1);
	argv[1] = "text.in";
	printf("�������� �����: %s\n", argv[1]);
	//argv[1] = "text.in";
	if (fopen_s(&fp, argv[1], "r+") != NULL) {
		printf_s("�� ������� ������� ����!");
	}
	if (fopen_s(&litf, "text-help.in", "r") != NULL) {
		printf_s("�� ������� ������� ����!");
	}
	if (fopen_s(&lpout, "text.out", "w+") != NULL) {
		printf_s("�� ������� ������� ����!");
	}
	printf_s("�������� ��������� ������?\n\n"
		"1 ��\n"
		"2 ���\n");

	words = (Word*)malloc(SIZE * sizeof(Word));
	if (!(str = (char*)malloc(sizeof(char)*SIZE))) {
		printf("������: �������� ������.");
		exit(1);
	}
	if (!(lit = (char*)malloc(sizeof(char) * 30))) {
		printf("������: �������� ������.");
		exit(1);
	}
	if (!(s = (char*)malloc(sizeof(char)*SIZE))) {
		printf("������: �������� ������.");
		exit(1);
	}
	if (!(lol = (char*)malloc(sizeof(char)*SIZE))) {
		printf("������: �������� ������.");
		exit(1);
	}
	printf_s("\n\n����� � �����:\n\n");
	fgets(str, 200, fp);
	printf("%s", str);
de:
	printf_s("\n\n������� �����, ������� ������� �� ������ ��������� � ������:\n");
	if (!fgets(lit, 30, stdin) == NULL) {
		printf_s("������. �� �� ����� �����");
		rewind(stdin);
		goto de;
	}
	s = strtok_s(str, " ,.!", &nun);

	while (s != NULL) {
		count = 0;
		for (k = 0; k < strlen(lit); k++) {
			for (j = 0; j < strlen(s); j++) {
				if (toupper(lit[k]) == toupper(s[j])) {
					count++;
				}
			}
		}
		fprintf(lpout, "\n[%d]%s\n", count, s);
		printf_s("\n[%d]%s\n", count, s);
		words[i].plum = count;
		words[i].strk = s;
		if (words[i].plum > max) {
			max = words[i].plum;
			lol = words[i].strk;
		}
		i++;
		s = strtok_s(NULL, " ,.!", &nun);
	}
	printf_s("\n������������ ���������� ���������� � ����� : %s - [%d]\n\n", lol, max);
	free(str);
	free(s);
	free(lit);
	free(words);
	fclose(fp);
	fclose(lpout);
	return 0;
}

void Instruction() {
	printf("\t������������ ������ �9\n"
		"����� � ������ ����� ���������� ���������� ���������� �������� ����\n"
		"����� � ����� ���������� � ������\n"
		"1)������� � ���������: ");
}