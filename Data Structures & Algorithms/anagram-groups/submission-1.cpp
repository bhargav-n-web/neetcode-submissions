class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(auto x:strs){
            int c[26]={0};
            for(auto y:x){
                c[y-'a']++;
            }
            string key="#";
            for(int i=0;i<26;i++){
                key=key+to_string(c[i])+"#";
            }
            um[key].push_back(x);
        }
        vector<vector<string>> ans;
        for(auto y: um){
            ans.push_back(move(y.second));
        }
        return ans;
    }
};
