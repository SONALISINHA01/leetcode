class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    void dfs(vector<vector<char>> &board,int n, int m, int i, int j){
        if(i>=n||j>=m||i<0||j<0){
            return;
        }
        if(board[i][j]=='.'){
            return;
        }
        board[i][j]='.';
        for(int k =0;k<4;k++){
            dfs(board,n,m,i+dx[k],j+dy[k]);
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]=='X'){
                    ans++;
                    dfs(board,n,m,i,j);
                }
            }
        }
        return ans ;
    }
};