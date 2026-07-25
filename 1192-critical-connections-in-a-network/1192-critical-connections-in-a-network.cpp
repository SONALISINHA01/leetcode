class Solution {
public:
    int timer =1;
    void dfs(int node,int parent,auto &adj,auto &vis,auto& bridges,int t_in[],int low[]){
        vis[node]=true;
        t_in[node]=low[node]=timer;
        timer++;
        for(auto &it:adj[node]){
            if(it==parent)continue;
            if(vis[it]==false){
                dfs(it,node,adj,vis,bridges,t_in,low);
                low[node]=min(low[node],low[it]);
                if(low[it]>t_in[node]){
                    bridges.push_back({node,it});
                }
            }else{
                low[node]=min(low[it],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for(int i=0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        vector<vector<int>> bridges;
        vector<bool> vis(n,false);
        int t_in[n];
        int low[n];
        dfs(0,-1,adj,vis,bridges,t_in,low);
        return bridges;
    }
};