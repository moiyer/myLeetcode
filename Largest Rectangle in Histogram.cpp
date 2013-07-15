/*

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.



Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].



The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/
//2013/7/15 15:16:17
//求max((j - i) * min(height[j], height[i]))
//最直观的的当然是i,j两层循环,O(n^2)
//改进：归并法，每次查找最短板，比较左、右和中间，O(n log n),大数据超时
class Solution {
public:
	int largestRecursive(vector<int> &height, int left, int right)
	{
		if(left > right)return INT_MIN;
		if(left == right)return height[left];

		int min_val = INT_MAX;
		int min_index = -1;
		for(int i = left; i <= right; ++i)
			if(height[i] < min_val)
			{
				min_val = height[i];
				min_index = i;
			}

		return max(max(largestRecursive(height, left, min_index - 1), largestRecursive(height, min_index + 1, right)), min_val * (right - left + 1));
	}
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(height.size() == 0)return 0;
        return(largestRecursive(height, 0, height.size() - 1));
    }
};

//2013/7/15 15:53:10
//最原始的想法，以第i个为height时查找左右，大数据超时
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = height.size();
        if(size == 0)return 0;
        int largest = INT_MIN;

        for(int i = 0; i < size; ++i)
        {
        	int j = i;
        	while(j >= 0 && height[j] >= height[i])--j;
        	int k = i;
        	while(k < size && height[k] >= height[i])++k;
        	int area = (k - j - 1) * height[i];
        	if(area > largest)largest = area;
        }

        return largest;
    }
};

//2013/7/15 16:28:38
//别人的方法，用stack实现，比较巧妙，O(n)
//维护一个递增的栈，每次比较栈顶与当前元素。如果当前元素小于栈顶元素，则入站，
//否则合并现有栈，直至栈顶元素小于当前元素。结尾入站元素0，重复合并一次。
class Solution {
public:
	int largestRectangleArea(vector<int> &h) {
		stack<int> p;
		int i = 0, m = 0;
		h.push_back(0);
		while(i < h.size()) {
			if(p.empty() || h[p.top()] <= h[i])
				p.push(i++);
			else {
				int t = p.top();
				p.pop();
				m = max(m, h[t] * (p.empty() ? i : i - p.top() - 1 ));
			}
		}
		return m;
	}
};