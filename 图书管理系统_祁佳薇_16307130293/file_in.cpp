#pragma warning(disable:4996)
#include<iostream>
#include<fstream>
#include<sstream>
#include<ios>
#include<string>
#include"Library.h"
using namespace std;

Book* Book_in()
{
	FILE *p;
	Book *Bhead = new Book;
	Bhead->link = NULL;
	Book *b1, *b2;
	if ((p = fopen("book.txt", "r")) == NULL)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return NULL;
	}
	else
	{
		char s[200];
		fgets(s, 100, p);//������һ��
		b1 = new Book;
		fscanf(p, "%d%s%s%d%d\n", &b1->number, b1->name, b1->auther, &b1->exist, &b1->total);
		b1->link = NULL;
		Bhead = b1;
		while (!feof(p))
		{
			b2 = new Book;
			fscanf(p, "%d%s%s%d%d\n", &b2->number, b2->name, b2->auther, &b2->exist, &b2->total);
			b2->link = NULL;
			b1->link = b2;
			b1 = b1->link;
		}
		cout << "...�鼮��Ϣ��ȡ�ɹ���" << endl;
		return Bhead;
	}
}
/*void Book_out(Book *Bhead)
{
	FILE *p;
	Book *b = Bhead;
	if (b == NULL)
		return;
	else
	{
		if ((p = fopen("book.txt", "w")) == NULL)
			cout << "���ļ�ʧ�ܣ�" << endl;
		while (b != NULL)
		{
			//show���� showBook(b);
			fprintf(p, "%d%s%s%d%d\n", b->number, b->name, b->auther, b->exist, b->total);
			b = b->link;
		}
		cout << "�洢�鼮�ɹ���" << endl;
	}
}*/
Reader* Reader_in(Borrow** B2head)
{
	FILE *p;
	Reader *Rhead = new Reader;
	Rhead->link = NULL;
	(*B2head)->link = NULL;
	Reader *r1, *r2;
	Borrow *b1, *b2,*b3;
	b3 = NULL;
	if ((p = fopen("reader.txt", "r")) == NULL)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return NULL;
	}
	else
	{
		char s[200];
		fgets(s, 100, p);//������һ��
		r1 = new Reader;
		fscanf(p, "%d%s%d", &r1->number, r1->name, &r1->remain_num);//�ȶ���š�������ʣ��ɽ���
		for (int i = 0; i != 5; i++)//�ٶ��ѽ��鼮������5����
		{
			b1 = new Borrow;
			fscanf(p, "%d", &(r1->bor[i].number));
			fscanf(p, "%s", r1->bor[i].BorDate);
			if (r1->bor[i].number != 0)
			{
				b1->number = r1->bor[i].number;//ͬʱ�������ı���
				b1->reader_number = r1->number;
				for (int j = 0; j != 8; j++)
					b1->BorDate[j] = r1->bor[i].BorDate[j];
				b1->link = NULL;
				if (i == 0)
					*B2head = b1;
				else
				{
					b3 = *B2head;
					while (b3->link != NULL)
						b3 = b3->link;
					b3->link = b1;
				}
			}
		}
		r1->link = NULL;
		Rhead = r1;
		while (!feof(p))
		{
			r2 = new Reader;
			b2 = new Borrow;
			fscanf(p, "%d%s%d", &r2->number, r2->name, &r2->remain_num);
			for (int i = 0; i != 5; i++)
			{
				fscanf(p, "%d%s", &r2->bor[i].number, &r2->bor[i].BorDate);
				if (r2->bor[i].number != 0)
				{
					b2->number = r2->bor[i].number;
					b2->reader_number = r2->number;
					for (int j = 0; j != 8; j++)
						b2->BorDate[j] = r2->bor[i].BorDate[j];
					b2->link = NULL;
					b3 = *B2head;
					if (b3 == NULL)
						*B2head = b2;
					else
					{
						while (b3 ->link!= NULL)
							b3 = b3->link;
						b3->link = b2;
					}
				}
			}
			r2->link = NULL;
			r1->link = r2;
			r1 = r1->link;
		}
		cout << "...��������Ϣ��ȡ�ɹ���" << endl;
		return Rhead;
	}
}
/*void Reader_out(Reader *Rhead,Book *Bhead)
{
	FILE *p;
	Reader *r = Rhead;
	if (r == NULL)
		return;
	else
	{
		if ((p = fopen("reader.txt", "w")) == NULL)
			cout << "���ļ�ʧ�ܣ�" << endl;
		while (r != NULL)
		{
			//showReader(r, Bhead);
			fprintf(p, "%d%s%d", r->number, r->name, r->remain_num);
			for (int i = 0; i != 5; i++)
				fprintf(p, "%d%s", r->bor[i].number, r->bor[i].BorDate);
			r = r->link;
		}
		cout << "��������Ϣ�洢�ɹ���" << endl;
	}
}*/