#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

class StringsWork
{
private:
	char str[256];//������, ������� �������� ������
public:
	StringsWork()//����������� � ������� ������� ������ ������ �� ������
	{
		for (int i = 0; i < 256; i++)  str[i] = '\0';
	}

	void operator +(char*);//�������� ������ ������ � ������� �� ���������� �������� +
	void operator -(char*);//�������� ������ ������ � ������� �� ���������� �������� -
	void getStr();//����� ������ ������ �� �����
};

void StringsWork::operator +(char *s) //��� ������ ��������� �������� +
{
	strcat(str, s);
}
void StringsWork::operator -(char *s) //��� ������ ��������� �������� +
{
	int ct = strlen(str) - strlen(s);
	str[ct] = '\0';
}

void StringsWork::getStr()
{
	cout << str << endl << endl;//����� ����������� ������� ������ �� �����
}

int main()
{
	setlocale(LC_ALL, "rus");

	char *str1 = new char[strlen("� ��������� ��� ������;\n") + 1]; //������� ������ ��� �����
	char *str2 = new char[strlen("�� ����� �� ���� ������;\n") + 1];
	char *str3 = new char[strlen("� ��� � ����� ��� ������\n") + 1];
	char *str4 = new char[strlen("������ ���� �� ���� ���:\n") + 1];

	strcpy(str1, "� ��������� ��� ������;\n");//��������������
	strcpy(str2, "�� ����� �� ���� ������;\n");
	strcpy(str3, "� ��� � ����� ��� ������\n");
	strcpy(str4, "������ ���� �� ���� ���:\n");

	cout << "1) " << str1;
	cout << "2) " << str2;
	cout << "3) " << str3;
	cout << "4) " << str4 << endl;

	StringsWork story;//������� ������ � �������� � ���� ������ � ������� �������������� +
	story + str1;
	story + str4;
	story + str3;
	story + str2;
	story - str2;

	cout << "========================================" << endl;
	cout << "����, ����� ����������� �������� �����: " << endl;
	cout << "========================================" << endl << endl;
	story.getStr();
	
	
	//������, ��� ��� �������� ����� ������ �������� ���� ����� ���������� ��������, ��� � ������
	int a = 5;
	int b = 5;
	int c = 0;

	c = a + b;
	cout << "========================================" << endl << endl;
	cout << "a = " << a << endl << "b = " << b << endl;
	cout << "c = " << a << " + " << b << " = " << c << endl << endl;

	delete[] str4;//��������� ������
	delete[] str3;
	delete[] str2;
	delete[] str1;

	return 0;
}