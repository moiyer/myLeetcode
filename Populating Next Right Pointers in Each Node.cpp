/*

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

*/
//2013/8/27 16:39:36
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	// void connectCore(TreeLinkNode *root, TreeLinkNode **p_leftest, TreeLinkNode **p_rightest)
	// {
	// 	if(root->left == NULL && root->right == NULL)
	// 	{
	// 		*p_rightest = root;
	// 		*p_leftest = root;
	// 		return;
	// 	}
	// 	root->left->next = root->right;

	// 	TreeLinkNode *lc_lefttest, *lc_rightest, *rc_lefttest, *rc_rightest;
		
	// 	if(root->left != NULL)connectCore(root->left, &lc_lefttest, &lc_rightest);
	// 	if(root->right != NULL)connectCore(root->right, &rc_lefttest, &rc_rightest);

	// 	lc_rightest->next = rc_lefttest;

	// 	*p_leftest = lc_lefttest;
	// 	*p_rightest = rc_rightest;
	// }

    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //TreeLinkNode *l, *r;
        //if(root != NULL)connectCore(root, &l, &r);
        if(root == NULL || root->left == NULL)return;
        TreeLinkNode *father_head = root;

        TreeLinkNode *cur;
        while(father_head->left != NULL)
        {
        	cur = father_head;
        	while(cur->next != NULL)
        	{
        		cur->left->next = cur->right;
        		cur->right->next = cur->next->left;
        		cur = cur->next;
        	}
        	cur->left->next = cur->right;

        	father_head = father_head->left;
        }
    }
};