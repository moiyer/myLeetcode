/*

Divide two integers without using multiplication, division and mod operator.

*/

//2013/6/12 20:32:01
//直接减会超时，所以将所减的数按指数增长
//注意int (-2147483648)取abs时会溢出

class Solution {
public:
	int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int result= 0;
		bool flag = true;
		vector<pair<int,int> > tmp;
		int vSize  = 0;
		int i;
		long long lDividend = dividend;
		long long lDivisor = divisor;

		if(lDivisor == 0 || lDividend == 0)return 0;

		if(lDividend < 0 && lDivisor < 0)
		{
			lDividend = abs(lDividend);
			lDivisor = abs(lDivisor);
			flag = true;
		}else if((lDividend < 0 && lDivisor > 0) || (lDividend > 0 && lDivisor < 0))
		{
			lDividend = abs(lDividend);
			lDivisor = abs(lDivisor);
			flag = false;
		}

		while(lDividend > 0)
		{
			if(vSize == 0)
			{
				lDividend -= lDivisor;
				pair<int, int> pr(1, lDivisor);
				tmp.push_back(pr);
				result++;
				vSize++;
			}else{
				i = vSize - 1;
				if(lDividend >= tmp[i].second)
				{
					lDividend -= tmp[i].second;
					result += tmp[i].first;
					pair<int, int> pr(tmp[i].first + tmp[i].first, tmp[i].second + tmp[i].second);
					tmp.push_back(pr);
					vSize++;
				}else{
					tmp.pop_back();
					vSize--;
					if(vSize == 0)break;
				}
			}
		}

		if(lDividend < 0)result--;

		if(flag)return result;
		else return 0 - result;
	}
};