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
	TreeNode* invertTree(TreeNode* root)
	{
		if(!root)	return root;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty())
		{
			
				TreeNode* tmp = q.front();
				q.pop();
				if(tmp->left or tmp->right)
				{
					TreeNode* sw = tmp->left;
					tmp->left = tmp->right;
					tmp->right = sw;
					if(tmp->left)	q.push(tmp->left);
					if(tmp->right)	q.push(tmp->right);
				}
			
		}
		return root;
	}
};