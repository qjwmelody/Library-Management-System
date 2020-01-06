#include<iostream>
#include<vector>

using namespace std;

void bubblesort(vector<int>& a)
{
	int l = a.size();
	for (int i = 0; i != l; i++)
	{
		for (int j = l - 1; j != i; j--)
		{
			if (a[j - 1] > a[j])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}
}

int main()
{
	vector<int> a;
	int temp,b;
	cout << "请输入滑动窗口的长度:";
	cin >> b;
	cout << "请为整数向量赋值:";
	while (cin >> temp)
		a.push_back(temp);

	for (int i = 0; i != a.size() - b + 1; i++)
	{
		vector<int> c;
		for (int j = 0; j != b; j++)
		{
			c.push_back(a[i + j]);
		}
		bubblesort(c);
		if (b % 2 != 0)
			cout << c[ b / 2]<<' ';
		else
			cout << (c[ b / 2 - 1] + c[ b / 2]) / 2<<' ';
	}
	cout << endl;
	system("pause");
	return 0;
}