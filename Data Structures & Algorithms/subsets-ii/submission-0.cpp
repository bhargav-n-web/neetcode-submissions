class Solution {
public:
    void backtracking(int pos,vector<int>&current,vector<int>& nums,vector<vector<int>>& result){
        result.push_back(current);
        for(int i=pos;i<nums.size();i++){
            if(i>pos&&nums[i]==nums[i-1])
                continue;
            current.push_back(nums[i]);
            backtracking(i+1,current,nums,result);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> current;
        sort(nums.begin(),nums.end());
        backtracking(0,current,nums,result);
        return result;
    }
};
