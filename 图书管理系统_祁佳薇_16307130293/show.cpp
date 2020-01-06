#pragma warning(disable:4996)
#include<iostream>
#include"Library.h"
using namespace std;

void showB(Book *p)
{
	printf("┌────────┬────────┬────────┬────────┬────────┐\n");
	printf("│   书籍编号     │     书名       │     著作者     │     现存量     │     库存量     │ \n");
	printf("├────────┼────────┼────────┼────────┼────────┤\n");
	printf("│%16d│%16s│%16s│%16d│%16d│\n", p->number, p->name, p->auther, p->exist, p->total);
	printf("└────────┴────────┴────────┴────────┴────────┘\n"); 
}

void showR(Reader *p, Book *Bhead)
{
	printf("┌────────┬────────┬────────┐\n");
	printf("│                │    读者信息    │                │\n");
	printf("├────────┼────────┼────────┤\n");
	printf("│    借阅证号    │       姓名     │   剩余可借     │\n");
	printf("├────────┼────────┼────────┤\n");
	printf("│%16d│%16s│%16d│\n",p->number,p->name,p->remain_num);
	printf("└────────┴────────┴────────┘\n");
	if (p->remain_num == 5)
	{
		cout << "这个人账下空空，竟然一本都没有借！" << endl;
		return;
	}
	printf("所借书籍信息\n");
	printf("┌────────┬────────┬────────┬────────┐\n");
	printf("│     书籍编号   │       书名     │      著作者    │     借书时间   │\n");
	printf("├────────┼────────┼────────┼────────┤\n");
	for (int i = 0; i != 5-p->remain_num; i++)
	{
		if (p->bor[i].number == 0 || p->bor[i].BorDate == 0)
			break;
		else
		{
			Book *q = searchBOOK_by_number(p->bor[i].number, Bhead);
			printf("│%16d│%16s│%16s│%16s│\n",q->number,q->name,q->auther,p->bor[i].BorDate);
			if(i!=5-p->remain_num-1)
				printf("├────────┼────────┼────────┼────────┤\n");	
		}
	}
	printf("└────────┴────────┴────────┴────────┘\n");
}

void Menu()//选择菜单
{
	cout << endl;
	printf("┌─────────────────────MENU───────────────────────┐\n");
	printf("│                                                                                            │\n");
	printf("│1、采编入库（新购入一本书，如果已在库，则库存量加一，否则新增一种书，需输入数量和编号）     │\n");
	printf("│2、添加新生（注册需输入姓名，产生一个借阅号）                                               │\n");
	printf("│3、借书                                                                                     │\n");
	printf("│4、还书                                                                                     │\n");
	printf("│5、按书号查找书籍                                                                           │\n");
	printf("│6、按书名查找书籍                                                                           │\n");
	printf("│7、按作者查找书籍                                                                           │\n");
	printf("│8、按借阅号查找借阅者，并显示其借阅情况                                                     │\n");
	printf("│9、查看所有逾期未还的情况                                                                   │\n");
	printf("│0、退出图书馆里系统                                                                         │\n");
	printf("└──────────────────请输入你需要的操作───────────────────┘\n");
	cout << endl;
}

