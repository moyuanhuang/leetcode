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
	bool isSymmetric(TreeNode* root)
	{
		if(!root or (!root->left and !root->right))	return true;
		if((root->left and !root->right) or (!root->left and root->right)) return false;
		queue<TreeNode*> s1, s2;
		s1.push(root->left);
		s2.push(root->right);
		while(!s1.empty() and !s2.empty())
		{
			TreeNode* l = s1.front();	s1.pop();
			TreeNode* r = s2.front();	s2.pop();
			cout << "comparing" << l->val << " " ;
			cout << r->val << endl;
			if(l->val != r->val)	return false;
			if(l->left and r->right)
			{
				s1.push(l->left);
				s2.push(r->right);
			}
			else if(!(!l->left and !r->right))	return false;
			if(l->right and r->left)
			{
				s1.push(l->right);
				s2.push(r->left);
			}
			else if(!(!l->right and !r->left))	return	false;
		}
		if(!(s1.empty() and s2.empty()))
			return false;
		return true;

	}
};