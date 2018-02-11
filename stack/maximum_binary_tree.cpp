// leetcod 654. Maximum Binary Tree

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = NULL, * cur;
        stack<TreeNode*> st;
        for(int n : nums){
            TreeNode* new_node = new TreeNode(n);
            if(!root){
                root = new_node;
                st.push(new_node);
                continue;
            }

            cur = st.top();
            if(n < cur->val){
                st.push(new_node);
                cur->right = new_node;
            }
            else {  // n > cur->val
                while(!st.empty()){
                    cur = st.top();
                    if(n < cur->val){
                        new_node->left = cur->right;
                        cur->right = new_node;
                        st.push(new_node);
                        break;
                    }
                    st.pop();
                }
                if(st.empty()){
                    new_node->left = root;
                    root = new_node;
                    st.push(new_node);
                }
            }
        }
        return root;

    }
};
