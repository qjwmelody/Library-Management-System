#include<iostream>
#include<string>

using namespace std;

//���ַ��������ַ�����
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

//ð�����򣬰�a-z����
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
	cout << "�������ַ���s1��s2" << endl;
	cin >> s1 >> s2;
	int l1 = s1.length();
	int l2 = s2.length();
	if (l1>l2)
		cout << "�������룡�ַ���s1�����ַ���s2��";
	int flag = 0;
	char* p1 = transfer(s1,0,l1);
	bubblesort(p1,l1);
	for (int i = 0; i!=l2-l1+1; i +=1)  //iΪ�ȽϿ�ʼ��λ��
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