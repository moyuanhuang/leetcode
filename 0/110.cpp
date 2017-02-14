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
	bool isBalanced(TreeNode* root)
	{
		return depth(root).second;
	}

	pair<int,bool> depth(TreeNode* root)
	{
		if(!root)	return {0, true};
		pair<int, bool> l = depth(root->left);
		pair<int, bool> r = depth(root->right);
		return {max(l.first, r.first) + 1, abs(l.first- r.first) <= 1 and l.second and r.second};
	}
};