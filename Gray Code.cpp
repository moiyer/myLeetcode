/*

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
//2013/7/16 15:55:58
//找规律题
//n=3时，正确的GrayCode应该是
//000
//001
//011
//010
//110
//111 //如果按照题意的话，只是要求有一位不同，这里也可以是100
//101
//100
//这样的话，规律就出来了，n=k时的Gray Code，相当于n=k-1时的Gray Code的逆序 加上 1<<k。

class Solution {
public:
	 vector<int> grayCode(int n) {  
      // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      vector<int> result;      
      result.push_back(0);  
      for(int i=0; i< n; i++)  
      {  
        int highestBit = 1<<i;  
        int len = result.size();  
        for(int i = len-1; i>=0; i--)  
        {  
          result.push_back(highestBit + result[i]);  
        }  
      }  
      return result;  
    }  
};