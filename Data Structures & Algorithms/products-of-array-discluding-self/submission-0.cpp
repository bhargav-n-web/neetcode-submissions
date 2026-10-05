class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int i=1,j=n-2;
        vector<int> pred(n,1),suff(n,1);
        vector<int> ans;
        while(i<n&&j>=0){
            pred[i]=pred[i-1]*nums[i-1];
            i++;
            suff[j]=suff[j+1]*nums[j+1];
            j--;
        }
        for(int i=0;i<n;i++){
            ans.push_back(pred[i]*suff[i]);
        }
        return ans;
    }
};
