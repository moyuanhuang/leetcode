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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if(!root)	return root;
		int mi = min(p->val,q->val);
		int ma = max(p->val, q->val);
		if(root->val < mi)
			return lowestCommonAncestor(root->right, p ,q);
		else if(root->val > ma)
			return lowestCommonAncestor(root->left, p ,q);
		else if(root->val >= mi and root->val <= ma)
			return root;
		return NULL;
	}
};