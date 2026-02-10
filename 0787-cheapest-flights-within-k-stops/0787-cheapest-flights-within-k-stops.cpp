class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto &f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]= 0;

        queue<pair<int,int>> q;
        q.push_back({src,0});

        int stops=0;
        while(stops<=k && !q.empty()){
            int sz = q.size();
            while(sz--){
                auto [node,cost]=q.front();
                q.pop();
                for(auto &it:adj[node]){
                    int next = it.first;
                    int price = it.second;
                    if(cost+price < dist[next]){
                        dist[next]=cost+price;
                        q.push({next,price});
                    }
                }
            }
            stops++;
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};