class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_length=0,left=0,max_freq=0,n=s.size();
        unordered_map<char,int> u;
        for(int right=0;right<n;right++){
            u[s[right]]++;
            max_freq=max(u[s[right]],max_freq);
            if(right-left+1-max_freq>k){
                u[s[left]]--;
                left++;
            }
            max_length=max(max_length,right-left+1);
        }
        return max_length;
    }
};
