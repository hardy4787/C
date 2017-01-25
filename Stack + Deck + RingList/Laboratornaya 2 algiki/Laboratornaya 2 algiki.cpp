#include "stdafx.h"
#include "stdlib.h"
#include "locale.h"
#include "stdio.h"
#include "conio.h"
#include "Windows.h"
//#include "time.h"

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102
#define _clear clear()

typedef struct Node_tag {
	int value;
	struct Node_tag *next;
} Node_t;

struct node {
	struct node *prev;
	int n;
	struct node *next;
}*h, *temp, *temp1, *temp2;
int count = 0;

void push(Node_t **head, int value);
Node_t* pop1(Node_t **head);
int peek(const Node_t* head);
size_t getSize(const Node_t *head);
size_t getSizeDek(const struct node *h);
void InstructionsStek(void);
void InstructionDek(void);
void InstructionRingList(void);
void PrimeInstruction(void);
void StekMenu();
void DekMenu();
void RingListMenu();
void insert1();
void insert2();
void traversebeg();
void traverseend(int);
void create();
void delete();
void ShowDek();
void GenCreate(int data);
void DekGeneration(int count);

void clear() {
	system("cls");
}

int main() {
	int i;
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//srand(time(NULL));
	PrimeInstruction();
	printf("\n�������� ��������: ");
	scanf_s("%d", &i);
	switch (i) {
	case 1:
		_clear;
		StekMenu();
		break;
	case 2:
		_clear;
		DekMenu();
		break;
	case 3:
		_clear;
		RingListMenu();
		break;
	default:
		_clear;
		main();
	}
	return 0;
}

/*************StackZone************/

void push(Node_t **head, int value) {
	Node_t *tmp = malloc(sizeof(Node_t));
	if (tmp == NULL) {
		exit(STACK_OVERFLOW);
	}
	tmp->next = *head;
	tmp->value = value;
	*head = tmp;
}

Node_t* pop1(Node_t **head) {
	Node_t *out;
	if ((*head) == NULL) {
		printf("\n���� ����.");
		_getch();
		_clear;
		main();
	}
	out = *head;
	*head = (*head)->next;
	return out;
}

int peek(const Node_t* head) {
	if (head == NULL) {
		printf("\n���� ����.");
		_getch();
		_clear;
		main();
	}
	return head->value;
}

size_t getSize(const Node_t *head) {
	size_t size = 0;
	while (head) {
		size++;
		head = head->next;
	}
	return size;
}

/*************DeckZone************/

void create() {
	int data;
	temp = (struct node *)malloc(1 * sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\n������� �������� �������� : ");
	scanf_s("%d", &data);
	temp->n = data;
	count++;
}

/*void GenCreate(int data) {
	temp = (struct node *)malloc(1 * sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	temp->n = data;
	count++;
}

void DekGeneration(int count) {
	int i; ������� �����
	for (i = 0; i < count; i++) {
		GenCreate(rand() % count + 1);
	}
}
*/
void insert1() {
	if (h == NULL) {
		create();
		h = temp;
		temp1 = h;
	}
	else {
		create();
		temp->next = h;
		h->prev = temp;
		h = temp;
	}
	ShowDek();
}

/* To insert at end */
void insert2() {

	if (h == NULL) {
		create();
		h = temp;
		temp1 = h;
	}
	else {
		create();
		temp1->next = temp;
		temp->prev = temp1;
		temp1 = temp;
	}
	ShowDek();
}
/* Traverse from beginning */
void traversebeg()
{
	temp2 = h;

	if (temp2 == NULL) {
		printf("������� �� ��� ������. \n");
		return;
	}
	printf("\n������ ������� : ");
	printf(" %d ", temp2->n);

	printf("\n");
}

/* To traverse from end recursively */
void traverseend(int i) {

	if (temp2 != NULL) {
		i = temp2->n;
		temp2 = temp2->next;
		traverseend(i);
	}
	else {
		printf(" %d", i);
	}
}

size_t getSizeDek(const struct node *h) {
	size_t size = 0;
	while (h) {
		size++;
		h = h->next;
	}
	printf("������ ���� = %d", size);
	return 0;
}

void delete() {
	int i = 1, pos;
	printf("\n1 � �����\n"
		"2 � ����\n");
	printf("\n�������� �������: : ");
	scanf_s("%d", &pos);
	temp2 = h;
	if (pos != 1 && pos != 2) {
		printf("������: ���������� ���� ��� �������� ������.\n");
		return;
	}
	if (pos == 2) {
		pos = count;
	}
	if (h == NULL) {
		printf("\n������ : ��� ����.\n");
		return;
	} else {
		while (i < pos) {
			temp2 = temp2->next;
			i++;
		}
		if (temp2->next == NULL) {
			temp2->prev->next = NULL;
			free(temp2);
			printf("\n������� ������� ������");
			count--;
			printf("\n");
			ShowDek();
			return;
		}
		temp2->next->prev = temp2->prev;
		if (i != 1)
			temp2->prev->next = temp2->next;
		if (i == 1)
			h = temp2->next;
		printf("\n������ ������� ������");
		printf("\n");
		free(temp2);
	}
	count--;
	ShowDek();
}

void ShowDek()
{
	temp2 = h;
	printf("\n��� : ");
	while (temp2->next != NULL) {
		printf(" %d ", temp2->n);
		temp2 = temp2->next;
	}
	printf(" %d ", temp2->n);

	printf("\n");
	_getch();
}

/*************MenuZone************/

void PrimeInstruction(void) {
	printf("\t������� ����\n\n"
		"1 ����\n"
		"2 ���\n"
		"3 ��������� ������\n");
}

void InstructionsStek(void) {
	printf("\t����:\n\n"
		//"0 ������������� ��������� ����\n"
		"1 �������� �������\n"
		"2 ������� �������\n"
		"3 ������ ������� ��������\n"
		"4 �������� ������ �����\n"
		"5 ����� � ������� ����\n"
		"6 ��������� ���������\n");
}
void InstructionDek(void) {
	printf("\t���:\n\n"
		//"9 ������������� ��������� ���\n"
		"1 �������� �� ����\n"
		"2 �������� �� ���\n"
		"3 �������� �������� � �������� �������\n"
		"4 ������ �������� ��������\n"
		"5 ������ ������� ��������\n"
		"6 ��������� ������� ����\n"
		"7 ����� � ������� ����\n");
}
void InstructionRingList(void) {
	printf("\t��������� ������:\n\n"
		//"0 ������������� ��������� ������\n"
		"1 ����� ������� � �������� ���������\n"
		"2 ���������� ������ ������� � �������� ������\n"
		"3 �������� �������������� ������� �� ��� ����� ���������� ����\n"
		"4 �������� ������������ ������� �� ������\n"
		"5 �������� ������ �� �������\n"
		"6 ��������� ������� �\n");
}

void StekMenu() {
	setlocale(LC_ALL, "RUS");
	int i, choice;
	Node_t *head = NULL;
	Node_t *tmp;
	InstructionsStek();
	printf("\n�������� ��������: ");
	scanf_s("%d", &choice);
	while (TRUE) {
		switch (choice) {
		case 1://����������� �������� � ����;
			_clear;
			printf("������� �������� ��������: ");
			scanf_s("%d", &i);
			push(&head, i);
			printf("��� �������� � ���� ������� Enter");
			break;
		case 2://����������� �������� �� �����;
			tmp = pop1(&head);
			printf("������ �������: %d ", tmp->value);
			free(tmp);
			break;
		case 3://������ ������� ��������;
			printf("������� ������� �����: %d ", peek(head));
			break;
		case 4://��������� ������� �����;
			printf("������ ����� = %d\n", getSize(head));
			break;
		case 5:
			_clear;
			main();
		case 6:
			exit(0);
		}
		_getch();
		_clear;
		InstructionsStek();
		printf("\n�������� ��������: ");
		scanf_s("%d", &choice);
	}
	printf("End of run.\n");
}

void DekMenu() {
	int choice, ct;
	h = NULL;
	temp = temp1 = NULL;
	InstructionDek();
	printf("\n�������� ��������: ");
	scanf_s("%d", &choice);
	while (choice) {
		switch (choice) {
		/*case 9:
			printf_s("������� ���������� ���������");
			scanf_s("%d", &ct);
			DekGeneration(ct);
			ShowDek();
			break;*/
		case 1:
			insert1();
			break;
		case 2:
			insert2();
			break;
		case 3:
			delete();
			_getch();
			break;
		case 4:
			traversebeg();
			_getch();
			break;
		case 5:
			temp2 = h;
			if (temp2 == NULL)
				printf("\n������: ������ ���� ");
			else {
				printf("\n��������� ������� : ");
				traverseend(temp2->n);
				printf("\n");
			}
			_getch();
			break;
		case 6:
			getSizeDek(h);
			_getch();
			break;
		case 7:
			_clear;
			main();
		case 8:
			ShowDek();
		default:
			system("cls");
			InstructionDek();
			break;
		}
		_clear;
		InstructionDek();
		printf("\n�������� ��������: ");
		scanf_s("%d", &choice);
	}
}

void RingListMenu() {
	setlocale(LC_ALL, "RUS");
	int i, choice;
	Node_t *head = NULL;
	Node_t *tmp;
	InstructionRingList();
	printf("\n�������� ��������: ");
	scanf_s("%d", &choice);
	while (choice != 5) {
		switch (choice) {
		case 1://����������� �������� � ����;
			_clear;
			printf("������� �������� ��������, ������� �� ������ ��������: ");
			scanf_s("%d", &i);
			push(&head, i);
			printf("��� �������� � ���� ������� Enter");
			break;
		case 2://����������� �������� �� �����;
			tmp = pop1(&head);
			printf("������ �������: %d ", tmp->value);
			free(tmp);
			break;
		case 3://������ ������� ��������;
			printf("������� ������� �����: %d ", peek(head));
			break;
		case 4://��������� ������� �����;
			printf("������ ����� = %d\n", getSize(head));
			break;
		default:
			system("cls");
			InstructionsStek();
			break;
		}
		_getch();
		_clear;
		InstructionsStek();
		printf("\n�������� ��������: ");
		scanf_s("%d", &choice);
	}
	printf("End of run.\n");
}
