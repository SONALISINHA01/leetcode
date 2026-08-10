class Solution {
public:
    int timer=1;
    void dfs(int par,int node, auto & adj,auto& visited, auto &bridges,auto& t_in, auto &low){
        visited[node]=true;
        t_in[node]=low[node]=timer++;
        for(auto it : adj[node]){
            if(it == par)continue;
            if(visited[it]==false){
                dfs(node,it,adj,visited,bridges,t_in,low);
                low[node]=min(low[node],low[it]);
                if(low[it]>t_in[node]){
                    bridges.push_back({node,it});
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for(int i =0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        vector<bool> visited(n,false);
        vector<int> t_in(n);
        vector<int> low(n);
        vector<vector<int>> bridges;
        dfs(-1,0,adj, visited,bridges,t_in, low);
        return bridges;
    }
};