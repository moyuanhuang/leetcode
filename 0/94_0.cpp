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
	vector<int> inorderTraversal(TreeNode* root)
	{
		stack<TreeNode*> s;
		vector<int> ret;
		TreeNode* cur = root;

		while(!s.empty() or cur)
		{
			if(cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			else
			{
				cur = s.pop();
				ret.push_back(cur->val);
				cur = cur->right;
			}
		}
		
		return ret;
	}
};