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
    int index=0; unordered_map<int, int> indices;
    TreeNode* dfs(int left,int right,vector<int>& preorder){
        if(left>right)
            return nullptr;
        TreeNode* t=new TreeNode(preorder[index]);
        int in_index=indices[preorder[index++]];
        t->left=dfs(left,in_index-1,preorder);
        t->right=dfs(in_index+1,right,preorder);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n=inorder.size();
        for(int i=0;i<n;i++){
            indices[inorder[i]]=i;
        }
        return dfs(0,n-1,preorder);

    }
};
