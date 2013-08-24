/*

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:

    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/
//2013/8/24 11:03:44
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
	bool isSymmetricCore(TreeNode *p, TreeNode* q)
	{
		if(p == NULL && q == NULL)return true;
		else if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;

		if(p->val != q->val)return false;

		return isSymmetricCore(p->left, q->right) && isSymmetricCore(p->right, q->left);
	}

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL)return true;

        return isSymmetricCore(root->left, root->right);
    }
};