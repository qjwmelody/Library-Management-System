#pragma once
#include<iostream>
struct Book {
	long number;//书籍编号
	char name[50];//书名
	char auther[20];//著作者
	int exist;//现存量
	int total;//库存量
	struct Book *link;
};//书籍结构
struct Borrow {
	long number;//书籍编号
	long reader_number;//读者编号
	char BorDate[8];//借书日期（20180116的格式）
	struct Borrow *link;
	Borrow() {
		number = reader_number = 0;
		for (int i = 0; i != 8; i++)
			BorDate[i] = 0;
		link = NULL;
	}
};//借书行为结构
struct Reader {
	long number;//借阅号
	char name[20];//借阅者姓名
	int remain_num;//借阅者剩余可以借阅书籍数量(每人限借5本)
	Borrow bor[5];//该借阅者的所有借阅行为
	struct Reader *link;
};//借阅者结构
template<class T>//因为有书和人两种，所以定义为模板类
struct index {
	long key;//编号
	T *address;//指针
	struct index *link;
};//索引结构


//文件读、写模块
Book* Book_in();
Reader* Reader_in(Borrow **B2head);//从文件加载信息初始化
//输出信息到文件
//void Book_out(Book *Bhead);
//void Reader_out(Reader *Rhead,Book *Bhead);


//查找模块
template<class T>
index<T>** init_index(T *Bhead);//创建哈希表

Book* searchBOOK_by_number(long num,Book *Bhead);
void searchBOOK_by_name(Book *Bhead);
void searchBOOK_by_auther(Book *Bhead);

Reader* searchREADER_by_number(long num, Reader *Rhead);


//采编入库、注册新生模块
void insert(Book *Bhead);
void regist(Reader *Rhead);


//借阅、归还模块
void borrow_book(Book *Bhead, Reader *Rhead, Borrow *B2head);
void return_book(Book *Bhead, Reader *Rhead, Borrow *B2head);


//罚款模块
int isLegal(char s[8]);//判断日期是否合法
int countFine(Reader *reader,Borrow *b,char s[8]);//计算此人借阅此书的罚款
void showFine(Borrow *B2head,Reader *Rhead);//罚款

//显示信息模块
void showB(Book *b);
void showR(Reader *r,Book *Bhead);
void Menu();//选择菜单