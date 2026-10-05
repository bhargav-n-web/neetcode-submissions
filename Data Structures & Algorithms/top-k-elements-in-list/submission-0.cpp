class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int> count_pair;
        vector<vector<int>> buckets(n+1);
        for(auto x:nums){
            count_pair[x]++;
        }
        for(auto x: count_pair){
            buckets[x.second].push_back(x.first);
        }
        for(int i=n;i>=0;i--){
            for(auto x:buckets[i]){
                ans.push_back(x);
                k--;
            }
            if(k<=0){
                return ans;
            }
        }
        
        return ans;
    }
};
