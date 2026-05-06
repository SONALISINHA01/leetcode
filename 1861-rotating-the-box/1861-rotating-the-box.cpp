class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxgrid) {
        int n = boxgrid.size();
        int m = boxgrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[j][n - 1 - i] = boxgrid[i][j];
            }
        }
        for (int col = 0; col < n; col++) {
            int empty = m - 1;
            for (int row = m - 1; row >= 0; row--) {
                if (ans[row][col] == '*') {
                    empty = row - 1;
                }
                else if (ans[row][col] == '#') {
                    ans[row][col] = '.';
                    ans[empty][col] = '#';
                    empty--;
                }
            }
        }
        return ans;
    }
};