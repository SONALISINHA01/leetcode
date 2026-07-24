class Solution {
public:
    int timer =1;
    void dfs(vector<vector<int>> &adj,int tin[],int low[],vector<vector<int>> &bridges,int node,int parent,vector<bool>& visited){
        visited[node]=true;
        tin[node]=low[node]=timer;
        timer++;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]==parent)continue;
            if(visited[adj[node][i]]==false){
                dfs(adj,tin,low,bridges,adj[node][i],node,visited);
                low[node]=min(low[node],low[adj[node][i]]);
                if(low[adj[node][i]]>tin[node]){
                    bridges.push_back({adj[node][i],node});
                }
            }else{
                low[node]=min(low[node],low[adj[node][i]]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> adj(n);
        for(int i =0;i<con.size();i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        vector<vector<int>> bridges;
        int tin[n];
        int low[n];
        vector<bool> visited(n,false);
        dfs(adj,tin,low,bridges,0,-1,visited);
        return bridges;

    }
};