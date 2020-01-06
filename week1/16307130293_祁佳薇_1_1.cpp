#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cout << "请输入一个字符串:" ;
	cin >> str;

	//最长无重复字符串开始元素下标
	int head = 0;
	//长度最大值length1
	int length1 = 1;

	for (int j = 0; str[j] != '\0';++j )
	{
		//用于更新length1
		int length2 = 1;

		//用于检验是否有重复字符
		int flag = 0;

		for (int k = j + 1; str[k] != '\0'; ++k)
		{
			for (int p=j;p!=k;++p)
			{
				if (str[k] == str[p])
				{
					flag = 1;
				}
			}
			if (flag == 1) break;
			length2++;
		}
		if (length2 > length1)
		{
			length1 = length2;
			head = j;
		}
	}
//三重循环，仍需优化

	cout<< "最大无重复字符子串长度为：" << length1 << endl;
	system("pause");
	return 0;
}