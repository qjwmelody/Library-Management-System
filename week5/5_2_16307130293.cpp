#include<iostream>
#include<string>
#include<vector>

using namespace std;

int palilen(string s)
{
	int length = s.size();
	if (length == 0)	return 0;
	if (length == 1)	return 1;
	int Max = 1;
	int left, right;	//left��right�ֱ�Ϊ�����Ӵ���������Ԫ���±�
	for (int i = 0; i != length - Max/2 + 1; i++)
	{//����ֱ���ұ�ʣ��Ԫ�ز��㵱ǰ����ȵ�һ��
		int max = 1;
		left = i - 1;
		right = i + 1;
		while (s[i] == s[right])	//�ظ�Ԫ��
		{
			right++;
			max++;
		}
		while (left != -1 && right != length&&s[left] == s[right])
		{
			if (right - left + 1 > max)
				max = right - left + 1;
			left--;
			right++;
		}
		if (max > Max)
			Max = max;
	}
	return Max;
}

int main()
{
	int n;
	cout << "�������ַ�������n:"<<endl;
	cin >> n;
	vector<int> result;
	string s;
	int j = 0;
	cout<<"������n���ַ���:"<<endl;
	while (j!=n&&cin >> s)
	{
		result.push_back(palilen(s));
		j++;
	}
	cout << "������Ӵ���������Ϊ:"<<endl;
	for (j = 0; j != n; j++)
		cout << result[j] << endl;
	system("pause");
	return 0;
}