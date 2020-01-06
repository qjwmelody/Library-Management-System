#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include"Library.h"
using namespace std;

//借书
void borrow_book(Book *Bhead, Reader *reader, Borrow *B2head)
{
	while (1)
	{
		printf("\n***借书***\n");
		cout << "请输入您要借阅的书籍编号：" ;
		long x;
		cin >> x;
		Book *b = searchBOOK_by_number(x, Bhead);
		if (b != NULL)//该书在库中存在
		{
			showB(b);//显示该书信息
			cout << "确认借阅此书籍吗？（请回答Y/N）" ;
			cin.clear();//清空输入流
			cin.ignore();
			char c1= getchar();
			char c2 = getchar();
			if (c1 == 'N')//如果不借，返回选择界面
				return;
			else
			{
				if (reader->remain_num == 0)
				{
					cout << "勤奋的您已借满五本书，先研究完手里的吧！" << endl;
					break;
				}
				else if (b->exist == 0)
					cout << "对不起您来晚了~该书已无库存，请看看其它书吧！" << endl;
				else//当库存充足且借阅者未借满五本时
				{
					//改变借阅者链表
					reader->remain_num--;
					int i = 0, j = 0;
					for (i; i != 5 && reader->bor[i].number != 0; i++);
					reader->bor[i].number = x;
					reader->bor[i].reader_number = reader->number;
					cout << "请输入当前时间：" ;
					cin.clear();
					cin.ignore();
					string s;
					cin >> s;
					for (; j != 8; j++)
						reader->bor[i].BorDate[j] = s[j];
					//改变书籍链表
					b->exist--;
					//改变借阅记录链表
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
			printf("***借阅成功***\n");
		}
		cout << "您要继续借阅其它书籍吗？（请回答Y/N）" ;
		cin.clear();
		cin.ignore();
		char t = getchar();
		char t2 = getchar();
		if (t == 'N')
			break;
	}
}

//还书
void return_book(Book *Bhead, Reader *reader, Borrow *B2head)
{
	printf("\n***还书***\n");
	cout << "请输入您要还的书籍编号：" ;
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
		printf("┌────────┬────────┬────────┬────────┐\n");
		printf("│    书籍编号    │      书名      │      著作者    │     借书时间   │\n");
		printf("├────────┼────────┼────────┼────────┤\n");
		printf("│%16d│%16s│%16s│%16s│\n", b->number, b->name, b->auther, reader->bor[i].BorDate);
		printf("└────────┴────────┴────────┴────────┘\n");
		cout << "确认归还此书吗？(请回答Y/N) " ;
		cin.clear();
		cin.ignore();
		char ch = getchar();
		char ch2 = getchar();
		if (ch == 'Y')
		{
			//改变书籍链表
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
			//改变读者链表
			b->exist++;
			//改变借阅记录链表
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
		printf("***还书成功***\n");
	}
	else cout << "编号有误！请仔细检查！" << endl;
}