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
	TreeNode* clone(TreeNode* root)
	{
		if(!root)	return NULL;
		TreeNode* newRoot = new TreeNode(root->val);
		newRoot->left = clone(root->left);
		newRoot->right = clone(root->right);
		return newRoot;
	}

public:
	vector<TreeNode*> generateTrees(int n)
	{
		vector<TreeNode*> ans(1, NULL);
		for(int  i = 0; i < =n; i++)
		{
			TreeNode* temp;
			for(int j = 0; j < ans.size(); ++j)
			{
				TreeNode* newRoot = new TreeNode(i);
				TreeNode* oldRoot = clone(ans[j]);
				newRoot->left = oldRoot;
				temp.push_back(newRoot);

				TreeNode* p = oldRoot;
					
			}
		}
	}
};