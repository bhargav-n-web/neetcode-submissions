class Solution {
public:
    int total_hours(vector<int>& piles,int k){
        int total=0;
        for(auto x:piles){
            total+=(x+k-1)/k;
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
       int right=INT_MIN, mid,res=0;
       for(int i=0;i<piles.size();i++){
        right=max(right,piles[i]);
       }
       int left=1;
       while(left<=right){
            mid=left+(right-left)/2;
            int hours=total_hours(piles,mid);
            if(hours<=h){
                res=mid;
                right=mid-1;
                
            }
            else if(hours>h){
                left=mid+1;
            }

       }  
       return res;
    }
};
