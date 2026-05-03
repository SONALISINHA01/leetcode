class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n =isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        //vector<vector<int>> ans(n,vector<int>(m,-1));
        //int hgt = -1;
        while(!q.empty()){
            int sz = q.size();
            //hgt++;
            while(sz--){
                auto [i,j]=q.front();
                q.pop();
                //if(ans[i][j]==-1)ans[i][j]=hgt;
                for(int k =0;k<4;k++){
                    int nx= i+dx[k], ny = j+dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && ans[nx][ny]==-1){
                        q.push({nx,ny});
                        ans[nx][ny]=ans[i][j]+1;
                    }
                }
            }
        }
        return ans;
    }
};