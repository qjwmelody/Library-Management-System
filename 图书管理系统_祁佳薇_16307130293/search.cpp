#pragma warning(disable:4996)
#include"Library.h"
using namespace std;

//用哈希函数建立索引表，用开散列法解决冲突
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
			q->link = p;//插入对应链表中
		}
		temp = temp->link;
	}
	return Hash_Table;
}

//按照编号查找书籍
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
		cout << "书库无记录，请先输入！" << endl;
		return NULL;
	}
	else 
	{
		long re = num % 97;
		q = table[re];
		if (q == NULL)
		{
			cout << "没有找到编号为" << num << "的书籍！" << endl;
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
				cout << "没有找到编号为" << num << "的书籍！" << endl;
				return NULL;
			}
		}
	}
	return NULL;
}
void searchBOOK_by_name(Book *Bhead)//根据书名查找书籍
{
	cout << "输入想要查找的书名：" ;
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
		cout << "没有找到书名为"<<name<<"的书籍！" << endl;
}
void searchBOOK_by_auther(Book *Bhead)//根据作者查找书籍
{
	cout << "请输入想要查找的作者：" ;
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
		cout << "没有找到作者为" << auther << "的书籍！" << endl;
}
//按照借阅号查找借阅者
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
		cout << "借阅者者库无记录，请先输入！" << endl;
		return NULL;
	}
	else
	{
		long re = num % 97;
		q = table[re];
		if (q== NULL)
		{
			cout << "没有找到编号为" << num << "的借阅者！" << endl;
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
				cout << "没有找到编号为" << num << "的借阅者！" << endl;
				return NULL;
			}
		}
	}
	return NULL;
}