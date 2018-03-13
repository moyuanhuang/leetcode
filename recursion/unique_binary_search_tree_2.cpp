// 95. Unique Binary Search Trees II
// remember it's binary tree! left can only be smaller than root->val, and right
// can only be larger than root->val

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
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0)  return vector<TreeNode*>();
        return gen_trees(1, n);
    }

private:
    vector<TreeNode*> gen_trees(int begin, int end){
        vector<TreeNode*> ret;
        if(begin > end){
            ret.push_back(new TreeNode(-1));
            return ret;
        }
        for(int i = begin; i <= end; i++){
            vector<TreeNode*> left = gen_trees(begin, i - 1);
            vector<TreeNode*> right = gen_trees(i + 1, end);
            for(TreeNode* l : left){
                for(TreeNode* r : right){
                    TreeNode* root = new TreeNode(i);
                    if(l->val != -1) {
                        root->left = l;
                        cout << l->val;
                    }
                    printf("<- %d ->", i);
                    if(r->val != -1) {
                        root->right = r;
                        cout << r->val;
                    }
                    cout << endl;

                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};
