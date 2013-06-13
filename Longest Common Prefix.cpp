/*

Write a function to find the longest common prefix string amongst an array of strings.

*/

//这是一道水题
//2013/6/8 13:33:01

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result = "";
        int stringNumber = 0;
        int pString = 0;
        char tp;
        int vSize = strs.size();

        if(strs.size() == 0)return result; 
        while(pString != strs[0].length())
        {
        	tp = strs[0][pString];
        	for(stringNumber = 1; stringNumber < vSize; stringNumber++)
        	{
        		if(strs[stringNumber].length() == pString || strs[stringNumber][pString] != tp)
        			return result;
        	}

        	result += tp;
        	pString++;
        }
        return result;
    }
};