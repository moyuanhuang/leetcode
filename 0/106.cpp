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
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
	{
		return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
	}

	TreeNode* helper(vector<int>& inorder, int in_start, int in_end, vector<int>& postorder, int post_start, int post_end)
	{
	    cout << "inorder: " << in_start<< "~" << in_end << " postOrder: " << post_start<< "~" << post_end<< endl;
		if(in_start >= in_end or post_start >= post_end)	return NULL;
		int mid = postorder[post_end - 1];
		int idx_mid = in_start-1;
		while(idx_mid < in_end and inorder[++idx_mid] != mid);
		int num = idx_mid - in_start;
		TreeNode* root = new TreeNode(mid);
		root->left = helper(inorder, in_start, idx_mid, postorder, post_start, post_start + num);
		root->right = helper(inorder, idx_mid+1, in_end, postorder, post_start + num, post_end - 1);
		
		return root;
	}
};