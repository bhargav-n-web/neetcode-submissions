class Solution {
public:
    unordered_map<int,int> exists;
    unordered_map<int,int> visited_length;
     int recurse(int temp){
        if(exists[temp]==0){
            return 0;
        }
        else if(visited_length[temp]>0){
            return visited_length[temp];
        }
        visited_length[temp]=recurse(temp+1)+1;
        return visited_length[temp];
    }
    int longestConsecutive(vector<int>& nums) {
        
        int ans=0;
        for(auto x:nums){
            exists[x]++;
            visited_length[x]=0;
        }
        for(int i=0;i<nums.size();i++){
            visited_length[nums[i]]=recurse(nums[i]);
            ans=max(ans,visited_length[nums[i]]);
        }
        return ans;
    }
};
