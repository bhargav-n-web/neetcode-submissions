class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int left=0,n=matrix[0].size(),m=matrix.size(),right=m*n-1;
     while(left<=right){
        int m=left+(right-left)/2;
        if(target<matrix[m/n][m%n]){
           right=m-1;
        }
        else if (target>matrix[m/n][m%n]){
            left=m+1;
        }
        else{
            return true;
        }
     }
     return false;   
    }
};
