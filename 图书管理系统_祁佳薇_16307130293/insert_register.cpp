#pragma warning(disable:4996)
#include<iostream>
#include"Library.h"
using namespace std;

//�ɱ����
void insert(Book *Bhead)
{
	printf("\n***�ɱ����***\n");
	Book *b1,*b2,*b3;
	long x,y;
	b3 = Bhead;
	cout << "�������鼮����:" ;
	cin >> y;
	while (1)
	{
		cout << "��ָ���������ı�ţ�200����������:" ;
		cin >> x;
		if (x <= 0 || x >= 9999)
		{
			cout << "boom!��ų�������Χ��" << endl;
			continue;
		}
		else
		{
			b2 = searchBOOK_by_number(x, Bhead);//���жϸñ���Ƿ��Ѵ���
			if (b2 == NULL)//��������ڣ�����ѭ�����������
				break;
			else
			{
				b2->total+=y;
				b2->exist+=y;
				printf("***���Ϊ%d���鼮�Ѵ��ڣ����ɹ���***\n", x);
				return;
			}
		}
	}
	cout << "������飡" << endl;
	b1 = new Book;//������鼮
	b1->number = x;
	cout << "������������" ;
	scanf("%s", b1->name);
	cout << "���������ߣ�" ;
	scanf("%s", b1->auther);
	b1->link = NULL;
	b1->total = y;
	b1->exist = y;
	while (b3->link != NULL)
		b3 = b3->link;
	b3->link = b1;
	printf("***�������ɹ�***\n");
}
//ע������
void regist(Reader *Rhead)
{
	printf("\n***ע��***\n");
	Reader *r,*r1;
	r = new Reader;
	r1 = Rhead;
	long count = 1;
	cout << "������������" ;
	scanf("%s", r->name);
	r->remain_num = 5;
	for (int i = 0; i != 5; i++)
	{
		r->bor[i].number = 0;
		r->bor[i].reader_number = 0;
		for (int j = 0; j != 8; j++)
			r->bor[i].BorDate[j] = ' ';
	}
	while (r1->link != NULL)
	{
		r1 = r1->link;
		count++;
	}
	count++;
	r->number = count;
	r->link = NULL;
	r1->link = r;
	printf("���Ľ��ĺ�Ϊ%d\n", count);
	printf("***ע��ɹ�***\n");
}