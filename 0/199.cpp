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
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> ans;
		if(!root)	return ans;
		helper(root, ans, 0);
	}
private:
	void helper(TreeNode* root, vector<int> &ans, int level)
	{
		if(!root)	return;
		if(level == ans.size())
			ans.push_back(root->val);
		helper(root->right, ans, level+1);
		helper(root->left, ans, level+1);
		return;
	}
};