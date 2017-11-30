// Leetcode 124. Binary Tree Maximum Path Sum
// Awesome problem!!!
// Notice that a path can go from left-child -> parent -> right-child
// so result need to be updated on EVERY NODE!!
// Also, return should be root->val + MAX(LEFT, RIGHT), because if you
// return (root->val + left + right), then it won't be a PATH

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
  int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    helper(root, res);
    return res;
  }

private:
  int helper(TreeNode* root, int& ret){
    if(!root) return 0;
    int left = max(0, helper(root->left, ret));
    int right = max(0, helper(root->right, ret));
    if(left + right + root->val > ret){
      ret = left + right + root->val;
    }
    return root->val + max(left, right);
  }
};
