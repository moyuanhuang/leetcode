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
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		if(!root)	return ans;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		TreeNode* last = root;
		while(!s.empty() and cur)
		{
			if((!cur->left and !cur->right) or (cur->left == last and !cur->right) or (cur->right == last))
			{
				ans.push_back(cur->val);
				last = cur;
				s.pop();
			}
			else
			{
				if(cur->right)	s.push_back(cur->right);
				if(cur->left)	s.push_back(cur->left);
			}
			cur = s.top();
		}
		return ans;
		
	}
};