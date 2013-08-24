/*

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

*/
//2013/8/24 17:03:55
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
	bool isBalancedCore(TreeNode *root, int *depth)
	{
		if(root == NULL)
		{
			*depth = 0;
			return true;
		}

		int left_depth, right_depth;
		bool left_isBalancde = isBalancedCore(root->left, &left_depth);
		bool right_isBalancde = isBalancedCore(root->right, &right_depth);

		int max_depth = left_depth > right_depth ? left_depth : right_depth;
		int min_depth = left_depth < right_depth ? left_depth : right_depth;

		*depth = max_depth + 1;
		return left_isBalancde && right_isBalancde && (max_depth - min_depth <= 1);
	}

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int depth;
        return isBalancedCore(root, &depth);
    }
};