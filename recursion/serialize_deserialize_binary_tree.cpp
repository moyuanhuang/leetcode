// leetcode 297. Serialize and Deserialize Binary Tree
// HARD
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        serialize(root, os);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << "len: " << data.size() << endl << "data: " << data << endl;
        istringstream is(data);
        return deserialize(is);
    }

private:
    void serialize(TreeNode* root, ostringstream& os) {
        if(root){
            os << root->val << " ";
            serialize(root->left, os);
            serialize(root->right, os);
        }
        else {
            os << "# ";
        }
        return;
    }

    TreeNode* deserialize(istringstream& is){
        string x;
        is >> x;
        if(x == "#"){
            return nullptr;
        }
        TreeNode* new_node = new TreeNode(stoi(x));
        new_node->left = deserialize(is);
        new_node->right = deserialize(is);
        return new_node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
