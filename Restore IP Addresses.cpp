/*

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/
//回溯，有点麻烦，注意有个地方容易忘记
class Solution {
public:
	bool isValidNum(string& s, int l , int r)
	{
		if(s[l] == '0' && r - l != 1)return false;

		if(atoi(s.substr(l, r - l).c_str()) < 256)
			return true;
		else return false;
	}

	void restoreIP(string& s, int sIndex, std::vector<string> &ret, string& tp, int dotNum)
	{
		// if(sIndex >= s.length())return;
		if(dotNum == 0)
		{
			if(isValidNum(s, sIndex, s.length()))
			{
				tp.append(s.substr(sIndex));
				ret.push_back(tp);
				tp.erase(tp.end() - (s.length() - sIndex), tp.end());//注意这里比较容易忘记
			}
			return;
		}

		int i = 1;
		for(; i <= 3; ++i)
		{
			if(sIndex + i >= s.length())break;

			if(isValidNum(s, sIndex, sIndex + i))
				{
					tp.append(s.substr(sIndex, i));
					tp.push_back('.');
					restoreIP(s, sIndex + i, ret, tp, dotNum - 1);
					tp.pop_back();
					for(int j = 0; j < i; ++j)
						tp.pop_back();
				}
		}
		return;
	}

    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<string> ret;
        string tp;

        if(s.empty() || s.length() < 4)return ret;
        restoreIP(s, 0, ret, tp, 3);
        return ret;
    }
};