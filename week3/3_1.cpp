#include<iostream>
#include<string>

using namespace std;

//将字符串存入字符数组
char* transfer(string s,int a,int l)
{
	char *p = new char[l];
	int i;
	for (i = 0; i != l; i++)
	{
		p[i] = s[a+i];
	}
	p[i] = '\0';
	return p;
}

//冒泡排序，按a-z排列
char * bubblesort(char* s,int l)
{
	for (int i = 0; i != l; i++)
	{
		for (int j = l-1; j !=  i ; j--)
		{
			if (s[j - 1]>s[j])
			{
				int temp = s[j];
				s[j] = s[j - 1];
				s[j - 1] = temp;
			}
		}
	}
	return s;
}

int main()
{
	string s1, s2;
	cout << "请输入字符串s1和s2" << endl;
	cin >> s1 >> s2;
	int l1 = s1.length();
	int l2 = s2.length();
	if (l1>l2)
		cout << "错误输入！字符串s1长于字符串s2！";
	int flag = 0;
	char* p1 = transfer(s1,0,l1);
	bubblesort(p1,l1);
	for (int i = 0; i!=l2-l1+1; i +=1)  //i为比较开始的位置
	{
		int j;
		char* p2 = transfer(s2, i, l1);
		bubblesort(p2,l1);
		for (j = 0; j != l1; j++)
		{
			if (p2[j] != p1[j])
				break;
		}
		if (j == l1)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1) cout << "True" << endl;
	else	cout << "False" << endl;
	system("pause");
	return 0;
}