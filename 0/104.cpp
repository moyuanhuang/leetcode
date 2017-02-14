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
	void traverse(TreeNode* tmp, int& max, int cur)
	{
		if(tmp == NULL)
		{
			max = cur > max? cur: max;
			return;
		}
		traverse(tmp->left, max, cur+1);
		traverse(tmp->right, max, cur+1);
		return;
	}

public:
	int maxDepth(TreeNode* root)
	{
		int max = 0;
		traverse(root, max, 0);
		return max;
	}
};