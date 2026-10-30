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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int>temp;
        while(!q.empty()){
            TreeNode* stopper=q.back();
            vector<int> res;
            while(true){
                TreeNode* t=q.front();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                res.push_back(t->val);
                q.pop();
                if(t==stopper)  break;
            }
            ans.push_back(res);
        }
        return ans;
    }
};
