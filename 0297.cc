/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:
    void dfs(TreeNode *r, ostringstream &os){
        if(!r){
            os<<"# ";
            return;
        }
        os<< r->val << " ";
        dfs(r->left, os);
        dfs(r->right, os);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        dfs(root, os);
        return os.str();
    }

    TreeNode *der(istringstream &is){
        string s;
        is>>s;
        if(s=="#"){
            return NULL;
        }

        auto r = new TreeNode(stoi(s));
        r->left = der(is);
        r->right =der(is);
        return r;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream is(data);
        return der(is);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
using Solution=Codec;
