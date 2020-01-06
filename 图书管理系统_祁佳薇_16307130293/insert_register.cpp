#pragma warning(disable:4996)
#include<iostream>
#include"Library.h"
using namespace std;

//采编入库
void insert(Book *Bhead)
{
	printf("\n***采编入库***\n");
	Book *b1,*b2,*b3;
	long x,y;
	b3 = Bhead;
	cout << "请输入书籍数量:" ;
	cin >> y;
	while (1)
	{
		cout << "请指定将入库书的编号（200以内整数）:" ;
		cin >> x;
		if (x <= 0 || x >= 9999)
		{
			cout << "boom!标号超出处理范围！" << endl;
			continue;
		}
		else
		{
			b2 = searchBOOK_by_number(x, Bhead);//先判断该编号是否已存在
			if (b2 == NULL)//如果不存在，跳出循环，添加新项
				break;
			else
			{
				b2->total+=y;
				b2->exist+=y;
				printf("***编号为%d的书籍已存在，入库成功！***\n", x);
				return;
			}
		}
	}
	cout << "添加新书！" << endl;
	b1 = new Book;//添加新书籍
	b1->number = x;
	cout << "请输入书名：" ;
	scanf("%s", b1->name);
	cout << "请输入作者：" ;
	scanf("%s", b1->auther);
	b1->link = NULL;
	b1->total = y;
	b1->exist = y;
	while (b3->link != NULL)
		b3 = b3->link;
	b3->link = b1;
	printf("***新书入库成功***\n");
}
//注册新生
void regist(Reader *Rhead)
{
	printf("\n***注册***\n");
	Reader *r,*r1;
	r = new Reader;
	r1 = Rhead;
	long count = 1;
	cout << "请输入姓名：" ;
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
	printf("您的借阅号为%d\n", count);
	printf("***注册成功***\n");
}