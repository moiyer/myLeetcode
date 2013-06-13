/*

You are given a string, S, and a list of words, L, that are all of the same length. 
Find all starting indices of substring(s) in S that is a concatenation of each word
 in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/

//2013/6/13 16:40:10
//思路比较朴素，直接一个一个向后移动查看
//使用map来看字符串是否在给定的串集合里，这点值得借鉴
class Solution {
public:

	bool check(string S, std::vector<string> &L, int cur, map<string, int> &data)
	{
		int subLength = L[0].length();
		int LSize = L.size();
		map<string, int>::iterator it;

		for(int i = 0; i < LSize; i += subLength)
		{
			it = data.find(S.substr(cur + i, subLength));
			if(it == data.end())return false;
			if(it->second != 0)return false;
			it->second++;
		}
		return true;
	}

    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int SLength = S.length();
        int LSize = L.size();

        map<string, int> data;
        std::vector<int> result;

        if(SLength == 0 || LSize == 0)return result;
        int subLength = L[0].length();

        for(int i = 0; i < SLength - subLength * LSize; ++i)
        {
            data.clear();
        	for(int j = 0; j < LSize; ++j)
        		data[L[j]] = 0;
        	if(check(S, L, i, data))
        	{
        		result.push_back(i);
        	}
        }

        return result;
    }
};