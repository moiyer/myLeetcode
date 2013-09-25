/*

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/

//2013/6/29 20:38:14
//经典的回溯，没有使用swap的方法
class Solution {
public:
	void back_trace(std::vector<int> &cur, std::vector<std::vector<int> > &ret, std::vector<int> &num)
	{
		if(num.size() == 0)
		{
			ret.push_back(cur);
			return;
		}

		int tp = 0;
		for(int i = 0; i < num.size(); ++i)
		{
			tp = num[i];
			cur.push_back(num[i]);
			num.erase(num.begin() + i);
			back_trace(cur, ret, num);
			num.insert(num.begin() + i, tp);
			cur.pop_back();
		}
	}

    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	std::vector<int> cur;
    	std::vector<std::vector<int> > ret;

    	int nSize = num.size();
    	back_trace(cur, ret, num);

    	return ret;    
    }
};

//八皇后问题，循环实现
﻿/*N皇后问题的非递归实现1*/
#include <iostream>

const int N=13;
void print();
bool can_place(int column,int row);
int cnt;
int a[N];
inline void place(int column,int row)
{
	a[column]=row;
}

inline int abs(int x)
{
	return x<0?-x:x;
}

void EightQueens(int column)
{
	int i=0,j=0;
	while(j<column)
		while(i<column)
		{
			if(can_place(j,i))
			{
				place(j,i);
				if(j==column-1)
				{
					print();
					if(j)
						--j;
					if(a[j]==column-1)
						if(j)
							--j;
						else
							return;
					i=a[j]+1;
					break;
				}
				else
				{
					i=0;
					++j;
					continue;
				}
			}
			else   //j不可能为0
			{
				if(i==column-1)
				{
					--j;
					if(a[j]==column-1)
						if(j)
							--j;
						else
							return;
					i=a[j]+1;
					break;
				}
				else
				{
					++i;
					continue;
				}
			}
		}

}

void print()
{
	++cnt;
}

bool can_place(int column,int row)
{
	for(int j=0;j!=column;++j)
	{
		if(a[j]==row)
			return false;
		if((column-j)==abs(a[j]-row))
			return false;
	}
	return true;
}

int main()
{
	EightQueens(N);
	std::cout<<cnt<<std::endl;
}

