/*

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/
//2013/8/23 21:32:32
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //2013/8/24 10:25:53
 //如果使用O(n)的空间比较容易
 //中序遍历，排序后重组
class Solution {
private:
    vector<int> val;
    vector<TreeNode* > index;
public:
    void traverse(TreeNode *node)
    {
        if (node == NULL)
            return;
            
        traverse(node->left);
        val.push_back(node->val);
        index.push_back(node);
        traverse(node->right);
    }
    
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        traverse(root);
        sort(val.begin(), val.end());
        for(int i = 0; i < val.size(); i++)
            index[i]->val = val[i];
    }
};

//2013/8/24 10:27:15
//使用o(1)的空间，没想出来，别人写的
//中序遍历，每次比较相邻元素
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
    void findpos(TreeNode *root, TreeNode * &pre, TreeNode * &p, TreeNode * &q) {
        if (!root) return;
        findpos(root->left, pre, p, q);
        if (pre && pre->val > root->val) {
            if (!p) p = pre;
            q = root;
        }
        pre = root;
        findpos(root->right, pre, p, q);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *p, *q, *pre;
        pre = p = q = NULL;
        findpos(root, pre, p, q);
        int tmp = p->val;
        p->val = q->val;
        q->val = tmp;
    }
};