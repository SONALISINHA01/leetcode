class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int column = matrix[0].size();
        vector<vector<int>> ans(rows, vector<int>(column, 0));
        for(int i =0 ,m =column-1 ;i<rows;i++,m--){
            for(int j = 0 , n= 0;j<column ;j++,n++){
                ans[n][m]=matrix[i][j];
            }
        }
        matrix = ans;
    }
};