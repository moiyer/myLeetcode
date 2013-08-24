/*

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

*/
//2013/8/24 18:30:00
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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL)return 1;

        int left = INT_MAX, right = INT_MAX;
        if(root->left != NULL)
            left = minDepth(root->left);
        if(root->right != NULL)
        	right = minDepth(root->right);

        return (left < right ? left : right) + 1;
    }
};