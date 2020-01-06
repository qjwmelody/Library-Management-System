#include<iostream>

using namespace std;

int main()
{
	int n, k;
	int a[10000];
	cout << "请输入n,k及n个整数:" << endl;
	cin >> n >> k;
	//存入数组
	for (int i = 0; i != n; ++i)
	{
		cin >> a[i];
	}

	//冒泡排序
	for (int i = 0; i != k; ++i)
	{
		for (int j = n - 1; j != i; --j)
		{
			if (a[j]>a[j - 1])
			{
				int temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
	}

	cout << "前k大的数为:" << endl;

	//输出
	for (int i = 0; i != k; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}