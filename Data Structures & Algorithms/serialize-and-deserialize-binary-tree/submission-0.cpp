/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
   string serialize(TreeNode* root) {
        if (!root) return "N,";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == nullptr) {
                s += "N,";
            } else {
                s += to_string(curr->val) + ",";
                q.push(curr->left);  // Safely push null pointers
                q.push(curr->right); // Safely push null pointers
            }
        }
        return s;
    }
    
    vector<string> values;
    void split(string data){
        values.clear();
        stringstream ss(data);
        string token;
        while (getline(ss, token,',')) {
            values.push_back(token);
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        split(data);
        // FIX: Added 'values.empty()' check to prevent out-of-bounds crash on empty inputs
        if(values.empty() || values[0] == "N")
            return nullptr;
            
        TreeNode* root=new TreeNode(stoi(values[0]));
        queue <TreeNode*> q;
        q.push(root);
        int index=1;
        while(!q.empty() && index < values.size()){
            TreeNode* t=q.front();
            q.pop();
            
            if(index < values.size()){
                string left=values[index++];
                if(left!="N"){
                    t->left=new TreeNode(stoi(left));
                    q.push(t->left);
                } else {
                    t->left=nullptr;
                }
            }
            
            if(index < values.size()){
                string right=values[index++];
                if(right!="N"){
                    t->right=new TreeNode(stoi(right));
                    q.push(t->right);
                } else {
                    t->right=nullptr;
                }
            }
        }
        return root;
    }
};
