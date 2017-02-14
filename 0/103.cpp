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
private:

public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root)
	{
		vector<vector<int>> ans;
		if(!root)	return ans;
		stack<TreeNode*> s;
		s.push(root);
		bool reverse = false;
		while(!s.empty())
		{
			stack<TreeNode*> ss;
			vector<int> level;
			while(!s.empty())
			{
				TreeNode* tmp = s.top();
				s.pop();
				level.push_back(tmp->val);
				if(!reverse)
				{
					if(tmp->left)	ss.push(tmp->left);
					if(tmp->right)	ss.push(tmp->right);
				}
				else
				{
					if(tmp->right)	ss.push(tmp->right);
					if(tmp->left)	ss.push(tmp->left);
				}
			}
			ans.push_back(level);
			s = ss;
			reverse = !reverse;
		}
		return ans;
	}
};