/*

Implement int sqrt(int x).

Compute and return the square root of x.

*/
//2013/7/5 16:13:25
//二分法，注意16行的条件
class Solution {
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 1;
        int r = x / 2 < std::sqrt(INT_MAX) ? x/2+1 : std::sqrt(INT_MAX);  //注意这里

        int m, pw;
        while(l <= r)
        {
        	m = (l + r) >> 1;
        	pw = m * m;
        	if(pw == x)return m;
        	else if(pw < x){
        		l = m + 1;
        		continue;
        	}else{
        		r = m - 1;
        		continue;
        	}
        }

        return m;
    }
};

//更快的是牛顿迭代法
//http://www.2cto.com/kf/201206/137256.html
class Solution {
public:
	const float EPS = 0.000000001;  

	int sqrt(int x) {  
            // Start typing your C/C++ solution below  
            // DO NOT write int main() function  
		if(x==0) return x;  
		float dividend = x;  
            float val = x;//最终  
            float last;//保存上一个计算的值  
            do  
            {  
            	last = val;  
            	val =(val + dividend/val) / 2;  
            }while(abs(val-last) > EPS);  
            int result = val;  
            if(result * result > x)  
            	result--;  
            return result;  
        }

    };