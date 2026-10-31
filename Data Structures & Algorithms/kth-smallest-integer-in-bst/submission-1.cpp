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
    void InorderTraversal(TreeNode* root,int& k,int& ans){
        if(k<=0)    return;
        if(!root)       return;
        InorderTraversal(root->left,k,ans);
        k--;
        if(k==0){
            ans=root->val;
        }
        InorderTraversal(root->right,k,ans);
       

    }
    int kthSmallest(TreeNode* root, int k) {
        int count =0, ans=-1;
        InorderTraversal(root,k,ans);
        return ans;


    }
};
