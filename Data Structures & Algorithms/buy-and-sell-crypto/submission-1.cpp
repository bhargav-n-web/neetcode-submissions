class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,n=prices.size(),ans=0,j;
        while(i<n-1){
            j=i+1;
           while(j<n&&prices[j]>prices[i]){
              ans=max(prices[j]-prices[i],ans);
              j++;
           }
           i=j;
        }
        return ans;
    }
};
