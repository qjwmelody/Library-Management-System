#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main()
{
	cout << "int����" << endl;
	List<int> list;
	cout<<"���������������:"<<endl;
	string s;
	int temp;
	while (cin >> s &&s !="end")	
	{//��������Ͳ�����������end����int�͵Ĳ���
		switch(s[0])
		{
			case 97:
			{
				cin >> temp;
				list.add(temp);
				break;
			}
			case 114:
			{
				cin >> temp;
				list.remove(temp);
				break;
			}
			case 102:
			{
				cin >> temp;
				list.find(temp);
				break;
			}
			case 112:
			{
				list.printList();
				break;
			}
			default:
				cout<<"��Ч���룡"<<endl;
		}
	}
	cout << "���������"<<endl;

	cout<<endl<<"string����";
	List<string> list2;
	cout<<endl<<"���������������:"<<endl;
	string s2;
	cin.ignore();	//���������
	while (getline(cin, s2) && s2 !="end")
	{//��������Ͳ�����������end����int�͵Ĳ���
		if (s2[0] == 112)
			list2.printList();
		else
		{
			int i, j;
			for (i = 0; s2[i] != ' '&&i != s2.size(); i++);//iΪ�ո�λ��
			i++;
			for (j = i + 1; s2[j] != ' '&&j != s2.size(); j++);//j-1Ϊ�ַ����ұ߽�
			string s3;
			s3 = s2.substr(i, j - i);	//s3Ϊ������ַ���
			switch (s2[0])
			{
			case 97:
			{
				list2.add(s3);
				break;
			}
			case 114:
			{
				list2.remove(s3);
				break;
			}
			case 102:
			{
				list2.find(s3);
				break;
			}
			default:
				cout << "��Ч���룡"<<endl;
			}
		}
	}
	cout << "���������"<<endl;
	system("pause");
	return 0;
}