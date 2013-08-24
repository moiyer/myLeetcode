/*

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/
//2013/8/15 20:46:19
//简单递归
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

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n == 0)
        {
            std::vector<TreeNode *> v;
            v.push_back(NULL);
        	return v;
        }
        else return generateTreesCore(1, n);


    }

    vector<TreeNode *> generateTreesCore(int l, int r)
    {
    	std::vector<TreeNode *> ret;
    	TreeNode *head ;
    	if(l == r)
    	{
    		head = new TreeNode(l);
    		ret.push_back(head);
    		return ret;
    	}else if(l > r)return ret;

    	for(int i = l; i <= r; ++i){
  
    		std::vector<TreeNode *> lt = generateTreesCore(l, i - 1);
    		std::vector<TreeNode *> rt = generateTreesCore(i + 1, r);

    		int lSize = lt.size();
    		int rSize = rt.size();
    		
    		if(lSize == 0)
    			for(int j = 0; j < rSize; ++j)
    			{
    				head = new TreeNode(i);
    				head->right = rt[j];
    				ret.push_back(head);
    			}
    		else if(rSize == 0)
    			for(int j = 0; j < lSize; ++j)
    			{
    				 head = new TreeNode(i);
    				head->left = lt[j];
    				ret.push_back(head);
    			}
    		else for(int j = 0; j < lSize; ++j)
    			for(int k = 0; k < rSize; ++k)
    			{
    				 head = new TreeNode(i);
    				head->left = lt[j];
    				head->right = rt[k];
    				ret.push_back(head);
    			}
    	}
    	return ret;
    }
};