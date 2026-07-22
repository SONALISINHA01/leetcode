class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    bool validate(vector<vector<int>>& heights, int mineffort){
        int n = heights.size();
        int m = heights[0].size();
        if(n == 1 && m == 1)return true;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        while(!q.empty()){
            int sz  = q.size();
            while(sz--){
                auto [i,j]=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx<n && ny<m && nx>=0 && ny>=0 && visited[nx][ny]==false && abs(heights[nx][ny]-heights[i][j])<=mineffort){
                        if(nx == n-1 && ny == m-1){
                            return true;
                        }
                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int st = 0, en =1e6;
        int mid;
        int ans  = INT_MAX;
        while(st<=en){
            mid = st + (en-st)/2;
            if(validate(heights,mid)){
                ans =  mid;
                en = mid-1;
            }else{
                st = mid+1;
            }
        }
        return ans;
    }
};