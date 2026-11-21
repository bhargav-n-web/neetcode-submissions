class Solution {
public:
    void g_p(int open,int close,int n,string& ans,vector<string>& result){
        if(ans.size()==2*n){
             result.push_back(ans);
             return;
        }
        if(open<n){
            ans.push_back('(');
            g_p(open+1,close,n,ans,result);
            ans.pop_back();
        }
        if(close<open){
            ans.push_back(')');
            g_p(open,close+1,n,ans,result);
            ans.pop_back();
        }
           
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        string ans="";
        g_p(0,0,n,ans,result);
        return result;
    }
};
