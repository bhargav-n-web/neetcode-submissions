class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>target){
                right--;
            }
            else if(nums[mid]<target){
                left++;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
