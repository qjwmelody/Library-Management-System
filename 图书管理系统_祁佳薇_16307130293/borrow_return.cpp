#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include"Library.h"
using namespace std;

//����
void borrow_book(Book *Bhead, Reader *reader, Borrow *B2head)
{
	while (1)
	{
		printf("\n***����***\n");
		cout << "��������Ҫ���ĵ��鼮��ţ�" ;
		long x;
		cin >> x;
		Book *b = searchBOOK_by_number(x, Bhead);
		if (b != NULL)//�����ڿ��д���
		{
			showB(b);//��ʾ������Ϣ
			cout << "ȷ�Ͻ��Ĵ��鼮�𣿣���ش�Y/N��" ;
			cin.clear();//���������
			cin.ignore();
			char c1= getchar();
			char c2 = getchar();
			if (c1 == 'N')//������裬����ѡ�����
				return;
			else
			{
				if (reader->remain_num == 0)
				{
					cout << "�ڷܵ����ѽ����屾�飬���о�������İɣ�" << endl;
					break;
				}
				else if (b->exist == 0)
					cout << "�Բ�����������~�������޿�棬�뿴��������ɣ�" << endl;
				else//���������ҽ�����δ�����屾ʱ
				{
					//�ı����������
					reader->remain_num--;
					int i = 0, j = 0;
					for (i; i != 5 && reader->bor[i].number != 0; i++);
					reader->bor[i].number = x;
					reader->bor[i].reader_number = reader->number;
					cout << "�����뵱ǰʱ�䣺" ;
					cin.clear();
					cin.ignore();
					string s;
					cin >> s;
					for (; j != 8; j++)
						reader->bor[i].BorDate[j] = s[j];
					//�ı��鼮����
					b->exist--;
					//�ı���ļ�¼����
					Borrow *b2, *b3;
					b2 = B2head;
					b3 = new Borrow;
					b3->number = x;
					j = 0;
					b3->BorDate[j++] = reader->bor[i].BorDate[j++];
					b3->link = NULL;
					b3->reader_number = reader->number;
					while (b2->link != NULL)
						b2 = b2->link;
					b2->link = b3;
				}
			}
			printf("***���ĳɹ�***\n");
		}
		cout << "��Ҫ�������������鼮�𣿣���ش�Y/N��" ;
		cin.clear();
		cin.ignore();
		char t = getchar();
		char t2 = getchar();
		if (t == 'N')
			break;
	}
}

//����
void return_book(Book *Bhead, Reader *reader, Borrow *B2head)
{
	printf("\n***����***\n");
	cout << "��������Ҫ�����鼮��ţ�" ;
	long x;
	cin >> x;
	int i, j;
	for (i = 0; i != 5; i++)
	{
		if (reader->bor[i].number == x)
		{
			j = 1;
			break;
		}
	}
	Book *b = searchBOOK_by_number(x, Bhead);
	if (b != NULL&&j == 1)
	{
		printf("�������������������Щ����������������Щ����������������Щ�����������������\n");
		printf("��    �鼮���    ��      ����      ��      ������    ��     ����ʱ��   ��\n");
		printf("�������������������੤���������������੤���������������੤����������������\n");
		printf("��%16d��%16s��%16s��%16s��\n", b->number, b->name, b->auther, reader->bor[i].BorDate);
		printf("�������������������ة����������������ة����������������ة�����������������\n");
		cout << "ȷ�Ϲ黹������(��ش�Y/N) " ;
		cin.clear();
		cin.ignore();
		char ch = getchar();
		char ch2 = getchar();
		if (ch == 'Y')
		{
			//�ı��鼮����
			reader->remain_num++;
			for (int i = 0; i != 5; i++)
			{
				if (reader->bor[i].number == x)
				{
					reader->bor[i].number = 0;
					for (int j = 0; j != 8; j++)
						reader->bor[i].BorDate[j] = 0;
					break;
				}
			}
			//�ı��������
			b->exist++;
			//�ı���ļ�¼����
			Borrow *b1=B2head;
			if (b1->number == x)
			{
				B2head = b1->link;
				delete b1;
			}
			else
			{
				while (b1 != NULL)
				{
					if (b1->link->number = x)
						break;
					else b1 = b1->link;
				}
				Borrow *b2 = b1->link;
				b1->link = b2->link;
				delete b2;
			}
		}
		printf("***����ɹ�***\n");
	}
	else cout << "�����������ϸ��飡" << endl;
}