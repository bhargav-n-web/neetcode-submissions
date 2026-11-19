class Solution {
public:
    void backtracking(int pos,int target,vector<int>& current,vector<int>& nums,vector<vector<int>>& result){
        if(target==0){
            result.push_back(current); 
            return;}
        for(int i=pos;i<nums.size();++i){
            if(target<nums[i]){
                break;
            }
            current.push_back(nums[i]);
            backtracking(i,target-nums[i],current,nums,result);
            current.pop_back();        
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        backtracking(0,target,current,nums,result);
        return result;
    }
};
