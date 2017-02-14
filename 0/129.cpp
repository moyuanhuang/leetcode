/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int sumNumbers(TreeNode* root)
	{
		return helper(root, 0);
	}

	int helper(TreeNode* root, int cur)
	{
		if(!root)	return 0;
		cur = cur*10 + root->val;
		if(!root->right and !root->left)
			return cur;
		return helper(root->right, cur) + helper(root->left, cur);
	}
};