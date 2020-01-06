#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int steps(string s1, int a1, string s2, int a2)
{
	if (a1 >= s1.size())
	{
		if (a1>s2.size())
			return 0;
		else
			return s2.size() - a2;
	}
	if (a2 >= s2.size())
	{
		if (a2>s1.size())
			return 0;
		else
			return s1.size() - a1;
	}
	if (s1[a1] == s2[a2])
		return steps(s1, a1 + 1, s2, a2 + 1);
	else
	{
		int t1 = steps(s1, a1, s2, a2 + 1);
		int t2 = steps(s1, a1 + 1, s2, a2);
		int t3 = steps(s1, a1 + 1, s2, a2 + 1);
		return min(t1, min(t2, t3)) + 1;
	}
}

int main()
{
	string s1,s2;
	cout<<"请输入字符串s1和s2:"<<endl;
	cin>>s1>>s2;
	int sum=steps(s1,0,s2,0);
	cout<<"修改步数为:"<<sum<<endl;
	system("pause");
	return 0;
}