class Solution {
public:
    void recurse(int pos,vector<int>& nums,vector<vector<int>>& ans){
        if(pos==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=pos;i<nums.size();i++){
            if(i==pos){
                recurse(pos+1,nums,ans);
            }
            else{
                swap(nums[i],nums[pos]);
                recurse(pos+1,nums,ans);
                swap(nums[i],nums[pos]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recurse(0,nums,ans);
        return ans;
    }
};
