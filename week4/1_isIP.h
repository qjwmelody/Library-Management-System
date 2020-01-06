#include<iostream>
#include<string>
#include<vector>

class isIP {
public:
	std::vector<std::string> restore(std::string& s)
	{
		int n = s.length();
		std::vector<std::string> buffer;
		std::vector<std::string> result;
		visit(s, 1, 0, n, buffer, result);
		return result;
	}
private:
	int visit(std::string &s, int index, int begin, int n, std::vector<std::string> &buffer, std::vector<std::string> &result)
	{
		if (begin >= n || index > 4)
		{
			return 1;
		}
		if (index == 4)
		{
			if (n - begin > 3)
			{
				return 1;
			}
			std::string temp = s.substr(begin);
			if (n - begin < 3 || temp <= "255")
			{
				if ((n - begin) > 1 && s[begin] == '0')
				{
					return 1;
				}
				buffer.push_back(temp);
				std::string a;
				for (int i = 0; i < 3; i++)
				{
					a += buffer[i] + ".";
				}
				a += buffer[3];
				result.push_back(a);
				buffer.pop_back();
			}
			return 0;
		}

		for (int len = 1; len <= 3; len++)
		{
			int flag = 0;
			if (len == 1)
			{
				buffer.push_back(s.substr(begin, len));
				visit(s, index + 1, begin + len, n, buffer, result);
				buffer.pop_back();
			}
			else if (len == 2)
			{
				if (s[begin] == '0')
				{
					flag = 1;
				}
				else
				{
					std::string temp = s.substr(begin, 2);
					buffer.push_back(temp);
					visit(s, index + 1, begin + len, n, buffer, result);
					buffer.pop_back();
				}
				if (flag == 1)
					len++;
			}
			else
			{
				if (s[begin] == '0')
				{
					flag = 1;
				}
				else
				{
					std::string temp = s.substr(begin, 3);
					if (temp <= "255")
					{
						buffer.push_back(temp);
						visit(s, index + 1, begin + len, n, buffer, result);
						buffer.pop_back();
					}
				}
				if (flag == 1)
					len++;
			}
		}
		return 0;
	}
}; 
