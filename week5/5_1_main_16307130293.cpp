#include<iostream>
#include<string>
#include"List.h"

using namespace std;

int main()
{
	cout << "int类型" << endl;
	List<int> list;
	cout<<"请输入操作及内容:"<<endl;
	string s;
	int temp;
	while (cin >> s &&s !="end")	
	{//读入操作和操作数，输入end结束int型的操作
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
				cout<<"无效输入！"<<endl;
		}
	}
	cout << "输入结束！"<<endl;

	cout<<endl<<"string类型";
	List<string> list2;
	cout<<endl<<"请输入操作及内容:"<<endl;
	string s2;
	cin.ignore();	//清空输入流
	while (getline(cin, s2) && s2 !="end")
	{//读入操作和操作数，输入end结束int型的操作
		if (s2[0] == 112)
			list2.printList();
		else
		{
			int i, j;
			for (i = 0; s2[i] != ' '&&i != s2.size(); i++);//i为空格位置
			i++;
			for (j = i + 1; s2[j] != ' '&&j != s2.size(); j++);//j-1为字符串右边界
			string s3;
			s3 = s2.substr(i, j - i);	//s3为读入的字符串
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
				cout << "无效输入！"<<endl;
			}
		}
	}
	cout << "输入结束！"<<endl;
	system("pause");
	return 0;
}