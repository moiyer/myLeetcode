/*

Implement pow(x, n).

*/

//2013/6/30 16:44:33
//递归实现，注意n可能为负数，且可能为-2147483648,所以下面的解法错误
class Solution {
public:
	double pow(double x, int n)
	{
		if(n < 0)return 1 / pow_positive(x, -1 * n);//错误，-1 * n，n可能为-2147483648
		else return pow_positive(x, n);
	}

    double pow_positive(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(n == 0)return 1.0;
    	else if(n == 1)return x;
 
    	double hf = pow_positive(x, n >> 1);
    	if(n % 2){
    		return hf * hf * x;
    	}else
    		return hf * hf;   
    }
};

//2013/6/30 17:01:28
double pow(double x, int n) {
    if (n == 0) return 1.0;
    // Compute x^{n/2} and store the result into a temporary
    // variable to avoid unnecessary computing
    double half = pow(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else if (n > 0)
        return half * half * x;
    else
        return half * half / x;
}