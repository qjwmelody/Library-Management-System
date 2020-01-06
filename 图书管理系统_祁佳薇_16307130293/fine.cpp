#include<iostream>
#include"Library.h"
using namespace std;

struct Date {
	int year;
	int month;
	int day;
};
Date tran(char s[8])
{
	Date date;
	char s2[8];
	for (int i = 0; i != 8; i++)
		s2[i] = s[i] - 48;
	date.year = s2[0]* 1000 + s2[1] * 100 + s2[2] * 10 + s2[3];
	date.month = s2[4] * 10 + s2[5];
	date.day = s2[6] * 10 + s2[7];
	return date;
}

int isLeapYear(int year)//�ж��Ƿ�������
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
int getDayOfMonth(int year,int month)//��ĳ��ĳ�µ�����
{
	int dayArr[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return month == 2 && isLeapYear(year) ? dayArr[month] + 1 : dayArr[month];
}
int isLegal(char s[8])//�ж������Ƿ�Ϸ�
{
	Date d;
	d=tran(s);
	if (d.year < 0)
		return 0;
	else if (d.month < 1 || d.month>12)
		return 0;
	else if (d.day<1 || d.day>getDayOfMonth(d.year, d.month))
		return 0;
	else return 1;
}
int countFine(Reader *reader, Borrow *b,char s[8])//������˽��Ĵ���ķ���
{
	Date d1, d2;
	d1 = tran(b->BorDate);//��������
	d2 = tran(s);//��ǰ����
	long daylen=0;
	for (int y = d1.year; y != d2.year; y++)
	{
		daylen += 365;
		if (isLeapYear(y))
			daylen++;
	}
	for (int m = 1; m != d2.month; m++)
		daylen += getDayOfMonth(d2.year, m);
	daylen += d2.day;
	for (int m = 1; m != d1.month; m++)
		daylen -=getDayOfMonth(d1.year, m);
	daylen -= d1.day;
	return daylen;
}

void showFine(Borrow *B2head,Reader *Rhead)//��ʾ��������δ���Ľ��ļ�¼
{
	cout << "�����뵱ǰ����" << endl;
	char data[8];
	cin >> data;
	if (isLegal(data))//�����ǰ���ںϷ�
	{
		Borrow *b = B2head;
		int count = 0;
		while (b != NULL)
		{
			//�������ڲ�
			int length=countFine(searchREADER_by_number(b->reader_number,Rhead),b,data);//����ʱ��
			if (length > 90)//�����ʱ�������£�
			{
				count++;
				int money=length-90;//����
				if (count == 1)
				{
					printf("�������������������Щ����������������Щ����������������Щ����������������Щ�����������������\n");
					printf("��   �鼮���     ��    �����߱��  ��     ��������   ��     ��������   ��      ����      �� \n");
					printf("�������������������੤���������������੤���������������੤���������������੤����������������\n");
					printf("��%16d��%16d��%16s��%16d��%16d��\n", b->number, b->reader_number, b->BorDate, length, money);
				}
				else
				{
					printf("�������������������੤���������������੤���������������੤���������������੤����������������\n");
					printf("��%16d��%16d��%16s��%16d��%16d��\n", b->number, b->reader_number, b->BorDate, length, money);
				}
			}
			b = b->link;
		}
		printf("�������������������ة����������������ة����������������ة����������������ة�����������������\n");
	}
	else
		cout << "�������ڴ���" << endl;
}