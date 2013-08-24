/*

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

*/
//2013/8/24 15:55:47
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
	TreeNode* buildTreeCore(std::vector<int> &inorder, std::vector<int> &postorder, int il, int ir, int pl, int pr)
	{
		if(il > ir || pl > pr)return NULL;

		int cur = postorder[pr];
		TreeNode *head = new TreeNode(cur);

		int i, j = pl;
		for(i = il; i <= ir; ++i, ++j)
			if(inorder[i] == cur)break;

		if(i > ir)return NULL;
		head->left = buildTreeCore(inorder, postorder, il, i - 1, pl, j - 1);
		head->right = buildTreeCore(inorder, postorder, i + 1, ir, j, pr - 1);

		return head;
	}

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int inorder_size = inorder.size();
        int postorder_size = postorder.size();

        return buildTreeCore(inorder, postorder, 0, inorder_size - 1, 0, postorder_size - 1);
    }
};