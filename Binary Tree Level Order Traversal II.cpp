/*

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:

[
  [15,7]
  [9,20],
  [3],
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/
//2013/8/24 14:20:08
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > ret;
        stack<std::vector<int> > sret;
        if(root == NULL)return ret;

        queue<TreeNode *> data;
 
        data.push(root);
        data.push(NULL);
        TreeNode *cur;
        std::vector<int> v1;
        std::vector<int> *cur_vec = &v1;
        while(data.size() > 1)
        {
        	cur = data.front();
        	data.pop();
        	if(cur == NULL)
        	{
        		sret.push(*cur_vec);
        		cur_vec = new vector<int>();
        		data.push(cur);
        		continue;
        	}
        	cur_vec->push_back(cur->val);
        	if(cur->left != NULL)data.push(cur->left);
        	if(cur->right != NULL)data.push(cur->right);
        }
        sret.push(*cur_vec);

        while(!sret.empty())
        {
        	ret.push_back(sret.top());
        	sret.pop();
        }
        return ret;
    }
};