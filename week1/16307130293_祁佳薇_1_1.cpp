#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cout << "������һ���ַ���:" ;
	cin >> str;

	//����ظ��ַ�����ʼԪ���±�
	int head = 0;
	//�������ֵlength1
	int length1 = 1;

	for (int j = 0; str[j] != '\0';++j )
	{
		//���ڸ���length1
		int length2 = 1;

		//���ڼ����Ƿ����ظ��ַ�
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
//����ѭ���������Ż�

	cout<< "������ظ��ַ��Ӵ�����Ϊ��" << length1 << endl;
	system("pause");
	return 0;
}