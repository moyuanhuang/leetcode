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
	bool hasPathSum(TreeNode* root, int sum)
	{
		return helper(root, sum, 0);
	}

	bool helper(TreeNode* root, int sum, int cur)
	{
		if(!cur)	return false;
		if(cur >= sum and (root->left or root->right))	return false;
		if(cur == sum and !root->left and !root->right)	return true;
		cur += root->val;
		return helper(root->left, sum, cur) or helper(root->right, sum, cur);
	}
};