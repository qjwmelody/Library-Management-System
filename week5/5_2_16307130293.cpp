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
	int left, right;	//left、right分别为回文子串左右两端元素下标
	for (int i = 0; i != length - Max/2 + 1; i++)
	{//遍历直至右边剩下元素不足当前最长长度的一半
		int max = 1;
		left = i - 1;
		right = i + 1;
		while (s[i] == s[right])	//重复元素
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
	cout << "请输入字符串个数n:"<<endl;
	cin >> n;
	vector<int> result;
	string s;
	int j = 0;
	cout<<"请输入n个字符串:"<<endl;
	while (j!=n&&cin >> s)
	{
		result.push_back(palilen(s));
		j++;
	}
	cout << "最长回文子串长度依次为:"<<endl;
	for (j = 0; j != n; j++)
		cout << result[j] << endl;
	system("pause");
	return 0;
}