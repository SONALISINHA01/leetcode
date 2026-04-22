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
    bool backtrack(vector<vector<char>>& board){
        for(int i =0;i<9;i++){
            for(int j =0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int val = 1;val<10;val++){
                        board[i][j]=val+'0';
                        if(checker(board,i ,j)&& backtrack(board)){
                            return true;
                        }
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};