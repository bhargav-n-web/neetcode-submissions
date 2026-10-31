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
    void goodnodes(TreeNode* root,int maximum,int& count ){
            if(!root)
                return ;
            if(maximum<=root->val){
                count++;
            }
            maximum=max(maximum,root->val);
            goodnodes(root->left,maximum,count);
            goodnodes(root->right,maximum,count);
            
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        goodnodes(root,root->val,count);
        return count;
    }
};
