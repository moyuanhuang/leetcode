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
	vector<vector<int>> pathSum(TreeNode* root, int sum)
	{
		vector<vector<int>> ans;
		if(!root)	return ans;
		vector<int> cur;
		helper(root, sum, 0, ans, cur);
		return ans;
	}

	void helper(TreeNode* root, int sum, int cur_sum, vector<vector<int>>& ans, vector<int> cur)
	{
	   // cout << root->val << endl;
		cur.push_back(root->val);
		cur_sum += root->val;
// 		if(cur_sum == sum and (root->left or root->right))	return;
		if(cur_sum == sum and !root->left and !root->right)
		{
			ans.push_back(cur);
			return;
		}
		if(root->left)	helper(root->left, sum, cur_sum, ans, cur);
		if(root->right)	helper(root->right, sum, cur_sum, ans, cur);
		return;
	}
};