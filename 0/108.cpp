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
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		if(nums.empty())	return NULL;
		return helper(nums, 0, nums.size()-1);
	}

	TreeNode* helper(vector<int>& nums, int a, int b)
	{
		if(a > b)	return NULL;

		int idx = (a+b)/2 + 1;
		int mid = nums[idx];
		TreeNode* root = new TreeNode(mid);
		root->left = helper(nums, a, mid-1);
		root->right = helper(nums, mid+1, b);
		return root;

	}
};