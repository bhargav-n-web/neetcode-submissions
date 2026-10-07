class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(10, vector<bool>(10, false)), 
                     cols(9, vector<bool>(10, false)), 
                     squares(9, vector<bool>(10, false));
         for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                int square=(i/3)*3+j/3,temp=board[i][j]-'0';
                if(rows[i][temp]||cols[j][temp]||squares[square][temp]){
                    return false;}
                rows[i][temp]=true;
                cols[j][temp]=true;
                squares[square][temp]=true;
            }
         }
         return true;

    }
};
