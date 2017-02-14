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
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		vector<vector<int>> ans;
		if(!root)	return ans;
		queue<TreeNode*> s;
		s.push(root);
		while(!s.empty())
		{
			queue<TreeNode*> ss;
			vector<int> level;
			while(!s.empty())
			{
				TreeNode* tmp = s.front();
				s.pop();

				if(tmp->left)	ss.push(tmp->left);
				if(tmp->right)	ss.push(tmp->right);

				level.push_back(tmp->val);
			}
			s = ss;
			ans.insert(ans.begin(), level);

		}
		return ans;
	}
};