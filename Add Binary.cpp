/*

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/
//2013/7/5 14:36:37
//水题
class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string::reverse_iterator ria = a.rbegin();
        string::reverse_iterator rib = b.rbegin();

        int flag = 0;
        map<char, int> mp;
        mp['0'] = 0;
        mp['1'] = 1;
        int sum = 0;
        string ret;
        while(ria != a.rend() && rib != b.rend())
        {
        	sum = mp[*ria] + mp[*rib] + flag;
        	flag = sum / 2;
        	sum = sum % 2;
        	ret.push_back(sum + '0');
        	ria++;
        	rib++;
        }

        while(ria != a.rend())
        {
        	sum = mp[*ria] + flag;
        	flag = sum / 2;
        	sum = sum % 2;
        	ret.push_back(sum + '0');
        	ria++;
        }

        while(rib != b.rend())
        {
        	sum = mp[*rib] + flag;
        	flag = sum / 2;
        	sum = sum % 2;
        	ret.push_back(sum + '0');
        	rib++;
        }

        if(flag)ret.push_back('1');

        string ll(ret.rbegin(), ret.rend());
        return ll;
    }
};