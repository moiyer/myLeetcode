/*

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

*/

//2013/6/8 10:34:58
//O(n)的复杂度，两边向中间逼近，每次都是矮的那个板向中间移动
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while(left < right)
        {
        	maxWater = max((right - left) * min(height[left], height[right]), maxWater);
        	if(height[left] < height[right])
        		left++;
        	else right--;
        }
        return maxWater;
    }
};