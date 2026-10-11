class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,n=s.size(),ans=0;
        unordered_map<char,int> count,index;
        for(int right=0;right<n;right++){
           
            if(count[s[right]]>0&&index[s[right]]>=left){
                left=index[s[right]]+1;
            }
            count[s[right]]++;
            index[s[right]]=right;
            
             ans=max(ans,right-left+1);

        }
       return ans;
    }
};
