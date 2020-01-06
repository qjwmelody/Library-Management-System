#include<iostream>

template<class Type> class List;//ǰ����������
template<class Type>
class Node{
friend class List<Type>;
public:
	Node(){next=NULL;}
	Node(Type item){data=item;next=NULL;}
private:
	Type data;
	Node<Type> *next;
};//�����

template<class Type>
class List{
public:
	List(){tail=head=new Node<Type>;}
	~List(){head=tail=NULL;}

	bool find(Type item)
	{//����
		Node<Type> *p=head->next;
		while(p!=NULL&&p->data!=item)
		{
			p=p->next;
		}
		if(p==NULL)
		{
			std::cout<<"false"<<endl;
			return 0;
		}
		else
		{
			std::cout<<"true"<<endl;
			return 1;
		}
	}

	bool add(Type item)
	{//����
		Node<Type> *p=new Node<Type>(item);
		if(!p)
		{
			std::cerr<<"Allocate Error!\n";
			return 0;
		}//�������ռ�ʧ�ܣ�����0
		else
		{
			tail->next = p;
			tail = p;
			std::cout << "true" << endl;
			return 1;
		}
	}

	bool remove(Type item)
	{//ɾ��
		if(!find(item))
			return 0;
		else
		{
			Node<Type> *p,*q;
			p=head;
			q=p->next;
			while(q!=NULL&&q->data!=item)
			{
				p=p->next;
				q=q->next;
			}
			p->next=q->next;
			delete q;
			return 1;
		}
	}

	void printList()
	{//��ӡ
		Node<Type> *p=head->next;
		while(p!=NULL)
		{
			std::cout<<p->data<<' ';
			p = p->next;
		}
		cout << endl;
	}
private:
	Node<Type> *head,*tail;
};//������