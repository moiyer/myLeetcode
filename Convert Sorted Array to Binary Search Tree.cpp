/*

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

*/
//2013/8/24 16:40:27
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	TreeNode *sortedArrayToBSTCore(std::vector<int> &num, int l, int r)
	{
		if(l > r)return NULL;

		int m = l + ((r - l) >> 1);

		TreeNode *cur = new TreeNode(num[m]);
		cur->left = sortedArrayToBSTCore(num, l, m - 1);
		cur->right = sortedArrayToBSTCore(num, m + 1, r);

		return cur;
	}
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.empty())return NULL;

        return sortedArrayToBSTCore(num, 0, num.size() - 1);
    }
};