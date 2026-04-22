class Solution {
    bool checker(vector<vector<char>> &board,int i , int j){
        char value = board[i][j];
        for(int m =0;m <9;m++){
            if(m==j){
                continue;
            }
            if(board[i][m]==value){
                return false;
            }
        }
        for(int m =0;m <9;m++){
            if(m==i){
                continue;
            }
            if(board[m][j]==value){
                return false;
            }
        }
        // we need to determine the cubical it belongs to , i think we will divide by 3
        // int cx = i%3, cy = j%3;
        int cx = (i/3)*3;
        int cy = (j/3)*3;
        for(int m=cx;m<cx+3;m++){
            for(int n=cy;n<cy+3;n++){
                if(m==i && n==j){
                    continue;
                }
                if(board[m][n]==value){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] != '.' && !checker(board,i,j)){
                    return false;
                }
            }
        }
        return true;
    }
};