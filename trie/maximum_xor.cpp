class Solution {
public:
    class TreeNode {
    public:
        TreeNode* next[2];
        TreeNode() {
            next[0] = NULL;
            next[1] = NULL;
        }
    };

    TreeNode* buildTrie(vector<int>& nums){
        TreeNode* root = new TreeNode();
        for(int n : nums){
            TreeNode *cur = root;
            for(int i = 31; i >= 0; --i){
                int index = (n >> i) & 1;
                if(cur->next[index] == NULL){
                    cur->next[index] = new TreeNode();
                }
                cur = cur->next[index];
            }
        }
        return root;
    }

    int findMax(TreeNode* root, int n){
        int ret = 0;
        TreeNode* cur = root;
        for(int i = 31; i >= 0; --i){
            int direction = (n >> i) & 1;
            int complement_direction = !direction;
            if(cur->next[complement_direction] != NULL){
                ret <<= 1;
                ret |= 1;
                cur = cur->next[complement_direction];
            }
            else {
                ret <<= 1;
                cur = cur->next[direction];
            }
        }
        return ret;
    }

    int findMaximumXOR(vector<int>& nums) {
        TreeNode* root = buildTrie(nums);
        int ret = 0;
        for(int n : nums){
            ret = max(ret, findMax(root, n));
        }
        return ret;
    }
};
