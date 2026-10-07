class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(auto x:strs){
            ans=ans+to_string(x.size())+'#'+x;
        }
        return ans;
    }
    
    vector<string> decode(string s) {
       int start=0,end=0,n=s.size();
       vector<string> ans;
       while(start<n){
            while(end<n&&s[end]!='#'){
                end++;
            }
            int len=stoi(s.substr(start,end-start));
            ans.push_back(s.substr(end+1,len));
            start=end+len+1;
            end=start;
       }
       return ans;
    }
};
