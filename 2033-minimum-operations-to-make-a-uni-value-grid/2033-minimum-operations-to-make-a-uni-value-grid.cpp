class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> arr;
        map<int,int> rem;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                arr.push_back(grid[i][j]);
                rem[grid[i][j]%x]++;
            }
        }
        if(rem.size()>1)return -1;
        sort(arr.begin(),arr.end());
        int z = arr.size();
        z = z/2; // this is median
        int num = arr[z];
        int ans =0;
        for(int i=0;i<arr.size();i++){
            int temp = abs(num-arr[i]);
            ans+=temp/x;
        }
        return ans;
    }
};