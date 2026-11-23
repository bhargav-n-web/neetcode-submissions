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

class Solution {
public:
    string convertTreeToString(TreeNode* root){
        stack<TreeNode*> st;
        st.push(root);
        string result;
        while(!st.empty()){
            TreeNode* ptr=st.top();
            st.pop();
            if(ptr==nullptr){
                result=result+"#"+"N";
            }
            else{
                result=result+"#"+to_string(ptr->val);
                st.push(ptr->right);
                st.push(ptr->left);
            }    
        }
        return result;     
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string s1=convertTreeToString(root);
        string s2=convertTreeToString(subRoot);
        if(s1.find(s2) != string::npos){
            return true;
        }
        return false;
    }
};
