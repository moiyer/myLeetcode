/*

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/
//2013/8/27 17:12:35
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 //循环来做
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root == NULL || (root->left == NULL && root->right == NULL))return;
        TreeLinkNode *father_head = root;
        TreeLinkNode *child_head;

        TreeLinkNode *cur;
        TreeLinkNode *c_pre, *c_cur;
        while(father_head != NULL)
        {
        	cur = father_head;
        	c_pre = NULL;
        	child_head = NULL;
        	while(cur != NULL)
        	{
        		if(cur->left != NULL || cur->right != NULL)
        		{
        			if(cur->left != NULL && cur->right != NULL)
        			{
        				if(child_head == NULL)
        				{
        					child_head = cur->left;
        					cur->left->next = cur->right;
        					c_pre = cur->right;
        				}else{
        					c_pre->next = cur->left;
        					cur->left->next = cur->right;
        					c_pre = cur->right;
        				}
        			}else if(cur->left != NULL)
        			{
        				if(child_head == NULL)
        				{
        					child_head = cur->left;
        					c_pre = cur->left;
        				}else{
        					c_pre->next = cur->left;
        					c_pre = cur->left;
        				}
        			}else{
        				if(child_head == NULL)
        				{
        					child_head = cur->right;
        					c_pre = cur->right;
        				}else{
        					c_pre->next = cur->right;
        					c_pre = cur->right;
        				}
        			}
        		}
        		cur = cur->next;
        	}
        	father_head = child_head;
        	child_head = NULL;
        }
    }
};

//2013/8/27 19:43:04
//别人写的，比较简洁
// the link of level(i) is the queue of level(i+1)
void connect(TreeLinkNode * n) {
    while (n) {
        TreeLinkNode * next = NULL; // the first node of next level
        TreeLinkNode * prev = NULL; // previous node on the same level
        for (; n; n=n->next) {
            if (!next) next = n->left?n->left:n->right;

            if (n->left) {
                if (prev) prev->next = n->left;
                prev = n->left;
            }
            if (n->right) {
                if (prev) prev->next = n->right;
                prev = n->right;
            }
        }
        n = next; // turn to next level
    }
}