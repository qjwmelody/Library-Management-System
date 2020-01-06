#pragma once
#include<iostream>
struct Book {
	long number;//�鼮���
	char name[50];//����
	char auther[20];//������
	int exist;//�ִ���
	int total;//�����
	struct Book *link;
};//�鼮�ṹ
struct Borrow {
	long number;//�鼮���
	long reader_number;//���߱��
	char BorDate[8];//�������ڣ�20180116�ĸ�ʽ��
	struct Borrow *link;
	Borrow() {
		number = reader_number = 0;
		for (int i = 0; i != 8; i++)
			BorDate[i] = 0;
		link = NULL;
	}
};//������Ϊ�ṹ
struct Reader {
	long number;//���ĺ�
	char name[20];//����������
	int remain_num;//������ʣ����Խ����鼮����(ÿ���޽�5��)
	Borrow bor[5];//�ý����ߵ����н�����Ϊ
	struct Reader *link;
};//�����߽ṹ
template<class T>//��Ϊ����������֣����Զ���Ϊģ����
struct index {
	long key;//���
	T *address;//ָ��
	struct index *link;
};//�����ṹ


//�ļ�����дģ��
Book* Book_in();
Reader* Reader_in(Borrow **B2head);//���ļ�������Ϣ��ʼ��
//�����Ϣ���ļ�
//void Book_out(Book *Bhead);
//void Reader_out(Reader *Rhead,Book *Bhead);


//����ģ��
template<class T>
index<T>** init_index(T *Bhead);//������ϣ��

Book* searchBOOK_by_number(long num,Book *Bhead);
void searchBOOK_by_name(Book *Bhead);
void searchBOOK_by_auther(Book *Bhead);

Reader* searchREADER_by_number(long num, Reader *Rhead);


//�ɱ���⡢ע������ģ��
void insert(Book *Bhead);
void regist(Reader *Rhead);


//���ġ��黹ģ��
void borrow_book(Book *Bhead, Reader *Rhead, Borrow *B2head);
void return_book(Book *Bhead, Reader *Rhead, Borrow *B2head);


//����ģ��
int isLegal(char s[8]);//�ж������Ƿ�Ϸ�
int countFine(Reader *reader,Borrow *b,char s[8]);//������˽��Ĵ���ķ���
void showFine(Borrow *B2head,Reader *Rhead);//����

//��ʾ��Ϣģ��
void showB(Book *b);
void showR(Reader *r,Book *Bhead);
void Menu();//ѡ��˵�