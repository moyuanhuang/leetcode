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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> ans;
		if(!root)	return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty())
		{
			queue<TreeNode*> qq;
			vector<int> level;
			while(!q.empty())
			{
				TreeNode* tmp = q.front();
				q.pop();
				level.push_back(tmp->val);
				if(tmp->left)	qq.push(tmp->left);
				if(tmp->right)	qq.push(tmp->right);
			}
			ans.push_back(level);
			q = qq;
		}
		return ans;
	}
};