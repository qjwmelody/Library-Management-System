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
	Rhead = Reader_in(&B2head);//���ļ��ж�ȡ�鼮�ͽ����ߵ���Ϣ�������鼮��������������ͽ��ļ�¼������

	printf("******************************��ӭ���븴����ѧ�Ž�У��ͼ�����ϵͳ*****************************\n");
	int choice = 1;
	while (choice != 0)
	{
		Menu();
		cin >> choice;
		switch (choice)
		{
		case 1:insert(Bhead); break;//�ɱ����
		case 2:regist(Rhead); break;//�������
		case 3://����
		{
			long x;
			cout << "���������ı�ţ�" ;
			cin >> x;
			Reader *reader = searchREADER_by_number(x, Rhead);
			if (reader != NULL)
				borrow_book(Bhead, reader, B2head);
			break;
		}
		case 4://����
		{
			long y;
			cout << "���������ı�ţ�" ;
			cin >> y;
			Reader *reader = searchREADER_by_number(y, Rhead);
			if(reader!=NULL)
				return_book(Bhead, reader, B2head); 
			break;
		}
		case 5://������Ų����鼮
		{
			long x;
			cout << "�������鼮���:" ;
			cin >> x;
			Book *b = searchBOOK_by_number(x, Bhead);
			if(b!=NULL)
				showB(b);
			cout << endl;
			break;
		}
		case 6://������������
			searchBOOK_by_name(Bhead); break;
		case 7://���������߲���
			searchBOOK_by_auther(Bhead); break;
		case 8://���ս��ĺŲ��ҽ�����
		{
			long y;
			cout << "����������߱�ţ�" ;
			cin >> y;
			Reader *r = searchREADER_by_number(y, Rhead);
			if(r!=NULL)
				showR(r,Bhead);
			cout << endl;
			break;
		}
		case 9://��ʾ��������δ���Ľ�����Ϣ
			showFine(B2head,Rhead);
		case 0://�˳�ϵͳ
			break;
		default:
			cout << "��������ȷ����ţ�" << endl; break;
		}
	}

	system("pause");
	return 0;
}