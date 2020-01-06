#pragma warning(disable:4996)
#include<iostream>
#include<string>
#include"Library.h"
using namespace std;

int main()
{
	Book *Bhead;
	Bhead = Book_in();
	Reader *Rhead;
	Borrow *B2head=new Borrow;
	Rhead = Reader_in(&B2head);//从文件中读取书籍和借阅者的信息，存入书籍链表、借阅者链表和借阅记录链表中

	printf("******************************欢迎进入复旦大学张江校区图书管理系统*****************************\n");
	int choice = 1;
	while (choice != 0)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:insert(Bhead); break;//采编入库
		case 2:regist(Rhead); break;//添加新生
		case 3://借书
		{
			long x;
			cout << "请输入您的编号：" ;
			cin >> x;
			Reader *reader = searchREADER_by_number(x, Rhead);
			if (reader != NULL)
				borrow_book(Bhead, reader, B2head);
			break;
		}
		case 4://还书
		{
			long y;
			cout << "请输入您的编号：" ;
			cin >> y;
			Reader *reader = searchREADER_by_number(y, Rhead);
			if(reader!=NULL)
				return_book(Bhead, reader, B2head); 
			break;
		}
		case 5://按照书号查找书籍
		{
			long x;
			cout << "请输入书籍编号:" ;
			cin >> x;
			Book *b = searchBOOK_by_number(x, Bhead);
			if(b!=NULL)
				showB(b);
			cout << endl;
			break;
		}
		case 6://根据书名查找
			searchBOOK_by_name(Bhead); break;
		case 7://根据著作者查找
			searchBOOK_by_auther(Bhead); break;
		case 8://按照借阅号查找借阅者
		{
			long y;
			cout << "请输入借阅者编号：" ;
			cin >> y;
			Reader *r = searchREADER_by_number(y, Rhead);
			if(r!=NULL)
				showR(r,Bhead);
			cout << endl;
			break;
		}
		case 9://显示所有逾期未还的借阅信息
			showFine(B2head,Rhead);
		case 0://退出系统
			break;
		default:
			cout << "请输入正确的序号！" << endl; break;
		}
	}

	system("pause");
	return 0;
}