/*

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/
//2013/8/24 18:47:56
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
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return false;
        if(root->left == NULL && root->right == NULL)
        	if(root->val == sum)return true;
        	else return false;

        sum -= root->val;

        bool l = false, r = false;
        if(root->left != NULL)
        	l = hasPathSum(root->left, sum);
        if(root->right != NULL)
        	r = hasPathSum(root->right, sum);

        return l || r;
    }
};