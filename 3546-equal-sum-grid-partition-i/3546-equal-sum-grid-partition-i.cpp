class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<long long> hori(n, 0), verti(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                hori[i] += grid[i][j];
            }
        }

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                verti[j] += grid[i][j];
            }
        }

        long long total = 0;
        for(auto x : hori) total += x;

        if(total % 2) return false;

        long long target = total / 2;

        long long curr = 0;
        for(int i = 0; i < n; i++){
            curr += hori[i];
            if(curr == target) return true;
        }

        curr = 0;
        for(int j = 0; j < m; j++){
            curr += verti[j];
            if(curr == target) return true;
        }

        return false;
    }
};