/*

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

//2013/6/9 16:00:41
//经典递归题目，有点像全排列,要多写几遍，熟练掌握，思考递归改循环

class Solution {
public:


    void letterIte(string letterMap[], string& digits, int depth, string& construct, std::vector<string> &v)
    {
    	if(depth == digits.length())
    	{
    		v.push_back(construct);
    		return;
    	}

    	for(int i = 0; i < letterMap[digits[depth] - 48].length(); ++i)
    	{
    		construct += letterMap[digits[depth] - 48][i];
    		letterIte(letterMap, digits, depth + 1, construct, v);
    		construct.pop_back();
    	}
    }


    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       	string letterMap[] = {"", " ", "abc", "def", "ghi", "jkl",  
        "mno", "pqrs", "tuv", "wxyz"};  

        std::vector<string> result;
        string construct;

        letterIte(letterMap, digits, 0, construct, result);

        return result;
    }
};


//2013/6/12 19:48:20
//循环实现，使用answer[]来模拟多层循环
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string letterMap[] = {"", " ", "abc", "def", "ghi", "jkl",  
        "mno", "pqrs", "tuv", "wxyz"};  
        int letterSize[] = {0, 1, 3, 3, 3, 3, 3, 4, 3, 4};

        std::vector<string> result;
        

        int size = digits.length();
        int* answer = new int[size]();
        int cur = 0, i, j;

        while(1)
        {
            string construct;
            for(j = 0; j < size; ++j)
                construct += letterMap[digits[j] - 48][answer[j]];
            result.push_back(construct);

            i = size - 1;
            while(i >= 0)
            {
                if(answer[i] < letterSize[digits[i] - 48] - 1)
                {
                    answer[i]++;
                    break;
                }else{
                    answer[i] = 0;
                    i--;
                }
            }
            if(i < 0)break;
        }

        return result;
    }
};