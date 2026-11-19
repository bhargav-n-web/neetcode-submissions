class Solution {
public:
    void backtracking(int pos,int target,vector<int>& nums,vector<int>& current,vector<vector<int>>& result){
        if(target==0){
            result.push_back(current);
            return;
        }
        if(pos==nums.size()){
            return ;
        }
        for(int i=pos;i<nums.size();i++){
            if(nums[i]>target){
                break;
            }
            if (i > pos && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);

            backtracking(i+1,target-nums[i],nums,current,result);
            current.pop_back();
        }
    
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
           vector<int>current;vector<vector<int>>result;
           sort(nums.begin(),nums.end());
           backtracking(0,target,nums,current,result);
           return result;
    }
};
