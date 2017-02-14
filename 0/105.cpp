class Solution {

public:
    /* from Preorder and Inorder Traversal */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty() or inorder.empty()) return NULL;
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    
    }

    TreeNode* helper(vector<int>& preorder, int ip, int sp,vector<int>& inorder,int ii,int si)
    {
        if(ip >= sp or ii >= si)
            return NULL;
        int mid = preorder[ip];
        int ir = ii - 1;
        while(ir <= si and inorder[++ir]!= mid);
        int dis = ir - ii;
        TreeNode* root = new TreeNode(mid);
        cout << "left of" << ir << " ";
        root -> left = helper(preorder,ip + 1,ip + dis + 1,inorder,ii,ir);
        cout << "right ";
        root -> right = helper(preorder,ip + 1 + dis,sp,inorder,ir + 1,si);
        return root;
    }
};