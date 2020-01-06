#pragma warning(disable:4996)
#include"Library.h"
using namespace std;

//�ù�ϣ���������������ÿ�ɢ�з������ͻ
template<class T>
index<T>** init_index(T *head)
{
	index<T>** Hash_Table;
	Hash_Table = new index<T>* [97];
	for (int i = 0; i !=97; i++)
	{
		Hash_Table[i] = NULL;
	}
	T *temp=head;
	index<T> *p,*q;
	while (temp != NULL)
	{
		p = new index<T>;
		p->key = temp->number;
		p->address = temp;
		p->link = NULL;
		long re = p->key % 97;
		q = Hash_Table[re];
		if (q == NULL)
		{
			q = p;
			Hash_Table[re] = q;
		}
		else
		{
			while (q!=NULL&&q->link != NULL)
				q = q->link;
			q->link = p;//�����Ӧ������
		}
		temp = temp->link;
	}
	return Hash_Table;
}

//���ձ�Ų����鼮
Book* searchBOOK_by_number(long num, Book *Bhead)
{
	index<Book> **table = init_index(Bhead);
	index<Book> *q;
	int flag = 0;
	for (int i = 0; i != 97; i++)
	{
		q = table[i];
		if (q!= NULL)
		{
			flag = 1;	break;
		}
	}
	if (flag == 0)
	{
		cout << "����޼�¼���������룡" << endl;
		return NULL;
	}
	else 
	{
		long re = num % 97;
		q = table[re];
		if (q == NULL)
		{
			cout << "û���ҵ����Ϊ" << num << "���鼮��" << endl;
			return NULL;
		}
		else
		{
			while (q != NULL)
			{
				if (q->key == num)
					return q->address;
				else q = q->link;
			}
			if (q == NULL)
			{
				cout << "û���ҵ����Ϊ" << num << "���鼮��" << endl;
				return NULL;
			}
		}
	}
	return NULL;
}
void searchBOOK_by_name(Book *Bhead)//�������������鼮
{
	cout << "������Ҫ���ҵ�������" ;
	char name[50];
	cin >> name;
	Book *b = Bhead;
	int flag = 0;
	while (b != NULL)
	{
		if (strcmp(name, b->name) == 0)
		{
			showB(b);
			b = b->link;
			flag = 1;
			cout << endl;
		}
		else b = b->link;
	}
	if (flag == 0)
		cout << "û���ҵ�����Ϊ"<<name<<"���鼮��" << endl;
}
void searchBOOK_by_auther(Book *Bhead)//�������߲����鼮
{
	cout << "��������Ҫ���ҵ����ߣ�" ;
	char auther[20];
	cin >> auther;
	Book *b = Bhead;
	int flag = 0;
	while (b != NULL)
	{
		if (strcmp(auther, b->auther) == 0)
		{
			showB(b);
			b = b->link;
			flag = 1;
			cout << endl;
		}
		else b = b->link;
	}
	if (flag == 0)
		cout << "û���ҵ�����Ϊ" << auther << "���鼮��" << endl;
}
//���ս��ĺŲ��ҽ�����
Reader* searchREADER_by_number(long num, Reader *Rhead)
{
	index<Reader> **table = init_index(Rhead);
	index<Reader> *q;
	int flag = 0;
	for (int i = 0; i != 97; i++)
	{
		q = table[i];
		if (q != NULL)
		{
			flag = 1;	break;
		}
	}
	if (flag == 0)
	{
		cout << "�������߿��޼�¼���������룡" << endl;
		return NULL;
	}
	else
	{
		long re = num % 97;
		q = table[re];
		if (q== NULL)
		{
			cout << "û���ҵ����Ϊ" << num << "�Ľ����ߣ�" << endl;
			return NULL;
		}
		else
		{
			while (q != NULL)
			{
				if (q->key == num)
					return q->address;
				else q = q->link;
			}
			if (q == NULL)
			{
				cout << "û���ҵ����Ϊ" << num << "�Ľ����ߣ�" << endl;
				return NULL;
			}
		}
	}
	return NULL;
}