class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool isvalid(int val , vector<vector<int>> & dup){
        int n = dup.size(),m = dup[0].size();
        if(dup[0][0]<val || dup[n-1][m-1]<val){
            return false;
        }
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        queue<vector<int>> q;
        q.push({0,0});
        visited[0][0]=true;
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            int i = v[0], j=v[1];
            for(int k =0;k<4;k++){
                int x = i+dx[k],y=j+dy[k];
                if(x>=0 && y>=0 && x<n &&y<m){
                    if(x==n-1 && y==m-1){
                        return true;
                    }
                    if(dup[x][y]>=val && !visited[x][y]){
                        q.push({x,y});
                        visited[x][y]=true;
                    }
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> dup = grid;
        int n = dup.size();
        int m = dup[0].size();
        queue<vector<int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                dup[i][j]+=-1;
                if(dup[i][j]==0){
                    q.push({i,j,1});
                }
            }
        }
        while(!q.empty()){
            auto v=q.front();
            int i = v[0], j = v[1], val = v[2];
            q.pop();
            for(int k=0;k<4;k++){
                if(i+dx[k]<n && j+dy[k]<m && i+dx[k]>=0 && j+dy[k]>=0){
                    int value= dup[i+dx[k]][j+dy[k]];
                    if(value!=-1 && value<=val){
                        continue;
                    }else if(value!=-1 && value>val){
                        dup[i+dx[k]][j+dy[k]]=val;
                        q.push({i+dx[k],j+dy[k],val+1});
                    }else{
                        dup[i+dx[k]][j+dy[k]]=val;
                        q.push({i+dx[k],j+dy[k],val+1});
                    }
                }
            }
        }
        int st=0,en=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                en = max(en,dup[i][j]);
            }
        }
        int mid;
        int ans =0;
        while(st<=en){
            mid = (en-st)/2 +st;
            if(isvalid(mid,dup)){
                ans =mid;
                st=mid+1;
            }else{
                en= mid-1;
            }
        }
        return ans;
    }
};