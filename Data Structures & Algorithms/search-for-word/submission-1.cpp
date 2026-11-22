class Solution {
public:
    int n,m;
    bool dfs(int i,int j,int index,vector<vector<char>>& board,vector<vector<bool>>&visited,string& word){
        if(index==word.size()) return true;
        if(i<0||i>=m) return false;
        if(j<0||j>=n) return false;
        if(board[i][j]==word[index]&&!visited[i][j]){
            visited[i][j]=true;
            bool up=dfs(i-1,j,index+1,board,visited,word);
            bool down=dfs(i+1,j,index+1,board,visited,word);
            bool left=dfs(i,j-1,index+1,board,visited,word);
            bool right=dfs(i,j+1,index+1,board,visited,word);
            visited[i][j]=false;
            if(!up&&!down&&!left&&!right)
                return false;
            return true;
        }
        else{
            return false;
        }
        

    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board[0].size();
        m=board.size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    bool exists=dfs(i,j,0,board,visited,word);
                    if(exists){
                        return true;}
                }
            }
        }
        return false; 
    }
};
