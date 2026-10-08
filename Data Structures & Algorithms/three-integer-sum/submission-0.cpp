class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int target=nums[i]*(-1),j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]>target)
                    k--;
                else if(nums[j]+nums[k]<target)
                    j++;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k&&(nums[j+1]==nums[j]))
                        j++;
                    while(j<k&&(nums[k]==nums[k-1]))
                        k--;
                    j++;
                    k--;
                   }
            }
            while(i+1<nums.size()&&nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};
