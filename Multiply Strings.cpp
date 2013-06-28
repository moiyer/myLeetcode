/*

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

*/

//2013/6/28 13:31:24
//Line 37~43, 处理乘法过程中在起始处产生的0。 比如， “9133”， “0”，直接乘的结果是“000000”， 而期待结果是“0”
class Solution {
public: 
string multiply(string num1, string num2) {  
      // Start typing your C/C++ solution below  
      // DO NOT write int main() function  
      if(num1.size() ==0 || num2.size() ==0) return 0;  
      string res(num1.size()+num2.size()+1, '0');  
      std::reverse(num1.begin(), num1.end());  
      std::reverse(num2.begin(), num2.end());  
      for(int i =0; i < num1.size(); i++)  
      {  
        int dig1 = num1[i] -'0';  
        int carry = 0;  
        for(int j = 0; j< num2.size(); j++)  
        {  
          int dig2 = num2[j] - '0';  
          int exist = res[i+j] -'0';          
          res[i+j] = (dig1*dig2+carry+ exist) % 10 +'0';    
          carry = (dig1*dig2+carry+exist)/10;  
        }  
        if(carry >0)  
        {  
          res[i+num2.size()] = carry + '0';  
        }  
      }  
      std::reverse(res.begin(), res.end());  
      int start =0;  
      while(res[start] =='0' && start < res.size())  
     {  
        start++;  
      }  
      if(start == res.size()) return "0";  
      return res.substr(start, res.size()-start);  
    }  
}; 