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
	void flatten(TreeNode* root)
	{
		TreeNode* now = root;
		while(now)
		{
			if(now->left)
			{
				TreeNode* new_right = now->left;
				while(new_right->right)
					new_right = new_right->right;
				new_right->right = now->right;
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
	}
};