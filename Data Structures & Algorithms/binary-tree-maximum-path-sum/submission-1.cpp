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
    int  maxPathSumAns(TreeNode* root,int& ans,const TreeNode* start){
        int ls=0,rs=0;
        if(root->left)
            ls=maxPathSumAns(root->left,ans,start);
        if(root->right)
            rs=maxPathSumAns(root->right,ans,start);
        int val;
        if(root==start){
            val=max(max(ls+root->val,rs+root->val),max(ls+rs+root->val,root->val));
            ans=max(ans,val);}
        else{
            val=max(root->val,max(ls+root->val,rs+root->val));
             ans=max(ls+rs+root->val,max(ans,val));
        }
        return val;
        }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathSumAns(root,ans,root);
        return ans;
    }
};
