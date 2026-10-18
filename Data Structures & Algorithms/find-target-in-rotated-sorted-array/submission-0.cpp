class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,n=nums.size(),r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(nums[m]<=nums[r]){
                r=m;
            }
            else{
                l=m+1;
            }
        }
        int k=l;l=0;r=n-1;
        while(l<=r){
            int left=(l+k)%n,right=(r+k)%n;
            int m=l+(r-l)/2,t=(m+k)%n;
            if(nums[t]<target){
                l=m+1;
            }
            else if (nums[t]>target){
                r=m-1;
            }
            else{
                return t;
            }
        }
        return -1;
    }
};
