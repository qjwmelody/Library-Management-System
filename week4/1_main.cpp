#include<iostream>
#include<string>
#include<vector>
#include"isIP.h"

using namespace std;

int main()
{
	string s;
	cout<<"������һ��IP��ַ:";
	cin>>s;
	isIP ip;
	vector<string> result=ip.restore(s);
	for (int i = 0; i!=result.size() ; i++)
	{
		cout<<"\""<<result[i]<<"\""<<"\n";
	}
	system("pause");
	return 0;
}