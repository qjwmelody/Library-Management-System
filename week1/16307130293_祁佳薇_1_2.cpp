#include<iostream>

using namespace std;

int main()
{
	int n, k;
	int a[10000];
	cout << "������n,k��n������:" << endl;
	cin >> n >> k;
	//��������
	for (int i = 0; i != n; ++i)
	{
		cin >> a[i];
	}

	//ð������
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

	cout << "ǰk�����Ϊ:" << endl;

	//���
	for (int i = 0; i != k; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;

	system("pause");
	return 0;
}