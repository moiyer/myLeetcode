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
//L里面可能有重复串
//大数据会超时
class Solution {
public:

	bool check(string S, std::vector<string> &L, int cur, int subLength, int LSize, map<string, int> &data, map<string, int> &number)
	{
		for(int i = 0; i < LSize * subLength; i += subLength)
		{
            string w = S.substr(cur + i, subLength);
			if(data.find(w) == data.end())return false;
			++data[w];
            if(data[w] > number[w])return false;
		}
		return true;
	}

    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int SLength = S.length();
        int LSize = L.size();

        map<string, int> data;
        map<string, int> number;
        std::vector<int> result;

        if(SLength == 0 || LSize == 0)return result;
        int subLength = L[0].length();

        for(int j = 0; j < LSize; ++j)
                ++number[L[j]];

        for(int i = 0; i <= SLength - subLength * LSize; ++i)
        {
        	for(int j = 0; j < LSize; ++j)
        		data[L[j]] = 0;
        	if(check(S, L, i, subLength, LSize, data, number))
        	{
        		result.push_back(i);
        	}
        }

        return result;
    }
};

//2013/6/14 14:03:38
//别人的解法，思路和我的一样，但是大数据勉强不会超时
class Solution {  
public:  
    vector<int> findSubstring(string S, vector<string> &L) {  
        map<string, int> words;  
        map<string, int> curStr;  
        for(int i = 0; i < L.size(); ++i)  
            ++words[L.at(i)];  
        int N = L.size();  
        vector<int> ret;  
        if(N <= 0)   return ret;  
        int M = L.at(0).size();  
        for(int i = 0; i <= (int)S.size()-N*M; ++i)  
        {  
            curStr.clear();  
            int j = 0;  
            for(j = 0; j < N; ++j)  
            {  
                string w = S.substr(i+j*M, M);  
                if(words.find(w) == words.end())  
                    break;  
                ++curStr[w];  
                if(curStr[w] > words[w])  
                    break;  
            }  
            if(j == N)  ret.push_back(i);  
        }  
        return ret;  
    }  
};