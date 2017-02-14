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
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		helper(root, ans);
		return ans;
	}

	void helper(TreeNode* root, vector<int>& ans)
	{
		if(!root)	return;
		ans.push_back(root->val);
		if(root->left)	helper(root->left, ans);
		if(root->right)	helper(root->right, ans);
		return;
	}
};