/*

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //中序遍历，循环实现
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode *> data;
        TreeNode *cur;
        std::vector<int> ret;

        cur = root;
        while(!cur || !data.empty())
        {
        	while(cur != NULL)
        	{
        		data.push(cur);
        		cur = cur->left;
        	}

        	if(!data.empty())
        	{
        		cur = data.top();
        		data.push(cur);
        		data.pop();
        		cur = cur->right;
        	}
        }

        return ret;
    }
};