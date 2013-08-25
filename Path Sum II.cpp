/*

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]

*/
//2013/8/24 18:57:56
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
	void dfs(std::vector<std::vector<int> > &ret, std::vector<int> &tp, TreeNode* root, int cur_sum, int sum)
	{
		tp.push_back(root->val);
		cur_sum += root->val;
		
		if(root->left == NULL && root->right == NULL)
		{
			if(cur_sum == sum)
			{
				ret.push_back(tp);
			}
			tp.pop_back();
			cur_sum -= root->val;
			return;
		}

		if(root->left)dfs(ret, tp, root->left, cur_sum, sum);
		if(root->right)dfs(ret, tp, root->right, cur_sum, sum);

		tp.pop_back();
		cur_sum -= root->val;
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> tp;
        std::vector<std::vector<int> > ret;
        if(root == NULL)return ret;
        dfs(ret, tp, root, 0, sum);
        return ret;
    }
};