/*

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/
//2013/8/23 20:31:45
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //递归，注意不是只要左右子树都是BST那么root就是BST
 class Solution {
 public:

 	bool isValidBSTCore(TreeNode *root, int *small, int *big) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 		if(root == NULL)return true;

 		bool l = true, r = true;
 		int ls = 0, lb = 0, rs = 0, rb = 0;
 		l = isValidBSTCore(root->left, &ls, &lb);
 		r = isValidBSTCore(root->right, &rs, &rb);
 		if(root->left != NULL)
 		{
 			*small = ls;
 			if(lb >= root->val)return false;
 		}
 		else *small = root->val;

 		if(root->right != NULL)
 		{
 			*big = rb;
 			if(rs <= root->val)return false;
 		}
 		else *big = root->val;

 		return l & r;
 	}

 	bool isValidBST(TreeNode* root)
 	{
 		int s, r;
 		return isValidBSTCore(root, &s, &r);
 	}
 };


 //别人写的，想法更好
 bool isBSTHelper(BinaryTree *p, int low, int high) {
    if (!p) return true;
    if (low < p->data && p->data < high)
        return isBSTHelper(p->left, low, p->data) && isBSTHelper(p->right, p->data, high);
    else
        return false;
}

bool isBST(BinaryTree *root) {
    // INT_MIN and INT_MAX are defined in C++'s <climits> library
    return isBSTHelper(root, INT_MIN, INT_MAX);
}