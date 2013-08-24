/*

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

*/
//2013/8/24 14:49:42
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //简单递归
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(preorder.empty() && inorder.empty())return NULL;

        int cur = preorder[0];
        TreeNode *head = new TreeNode(cur);
        std::vector<int>::iterator it = inorder.begin();
        std::vector<int>::iterator itp = preorder.begin() + 1;

        for(; it != inorder.end(); ++it, ++itp)
        {
            if(*it == cur)break;
        }

        if(it == inorder.end())return NULL;
        
        std::vector<int> a(preorder.begin() + 1, itp);
        std::vector<int> b(inorder.begin(), it);
        std::vector<int> c(itp, preorder.end());
        std::vector<int> d(it + 1, inorder.end());

        head->left = buildTree(a, b);
        head->right = buildTree(c, d);
        
        return head;
    }
};