class Solution {
public:
    bool isAlnum(char ch){
        if(ch>='a' && ch<='z')
            return true;
        if(ch>='A'&& ch<='Z')
            return true;
        if(ch>='0'&& ch<='9')
            return true;
        return false;
    }
    bool isPalindrome(string s) {
        int left=0,n=s.size(),right=n-1;
        while(left<right){
            while(left<n&&left<right&&!isAlnum(s[left])){
                left++;}
            while(right>=0&&right>left&&!isAlnum(s[right])){
                right--;}
            if(tolower(static_cast<unsigned char>(s[left]))!=tolower(static_cast<unsigned char>(s[right])))
                    return false;
            left++;
            right--;
        }
        return true;
    }
};
