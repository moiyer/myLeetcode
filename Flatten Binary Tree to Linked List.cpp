/*

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/
//2013/8/26 15:35:29
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //简单递归，注意下l_sub_right、r_sub_right、r_sub的初始值
class Solution {
public:
	TreeNode* flattenCore(TreeNode *root)
	{
		if(root->left == NULL && root->right == NULL)
			return root;

		TreeNode *l_sub_right = root, *r_sub_right = NULL, *r_sub = root->right;
		if(root->left != NULL)
		{
			l_sub_right = flattenCore(root->left);
			root->right = root->left;
			root->left = NULL;
		}

		r_sub_right = l_sub_right;
		if(r_sub != NULL)r_sub_right = flattenCore(r_sub);
		l_sub_right->right = r_sub;

		return r_sub_right;
	}

    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	if(root != NULL)flattenCore(root);    
    }
};