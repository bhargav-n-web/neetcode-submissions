class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();stack<int> st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="*"||tokens[i]=="+"||tokens[i]=="/"||tokens[i]=="-"){
                int right,left;
                right=st.top();st.pop();
                left=st.top();st.pop();
                if(tokens[i]=="+"){
                    st.push(left+right);
                }
                else if(tokens[i]=="-"){
                    st.push(left-right);
                }
                else if(tokens[i]=="*"){
                    st.push(left*right);
                }
                else{
                    st.push(left/right);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
