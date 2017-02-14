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
	int minDepth(TreeNode* root)
	{
	    if(!root)   return 0;
		int ans = INT_MAX;
		queue<pair<TreeNode*, int>> q;
		q.push({root, 1});
		while(!q.empty())
		{
			queue<pair<TreeNode*, int>> qq;
			while(!q.empty())
			{
				pair<TreeNode*, int> tmp = q.front();
				q.pop();
				TreeNode* node = tmp.first;
				if(!node->left and !node->right)
				{
				// 	cout << tmp.second << endl;
					ans = ans > tmp.second? tmp.second: ans;
					continue;
				}
				if(node->left)	qq.push({node->left, tmp.second + 1});
				if(node->right)	qq.push({node->right, tmp.second + 1});
			}
			q = qq;
		}
		return ans;
	}
};