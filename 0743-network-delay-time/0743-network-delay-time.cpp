class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m = times.size();
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i =0;i<m;i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int> timenode(n+1,INT_MAX);
        timenode[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            auto [dist,node]=pq.top();
            pq.pop();
            int sz = adj[node].size();
            for(int i =0;i<sz;i++){
                if(dist > timenode[node]) continue; //chatgpt added this edge 
                if(dist+adj[node][i].second < timenode[adj[node][i].first]){
                    timenode[adj[node][i].first]=dist+adj[node][i].second;
                    pq.push({dist+adj[node][i].second,adj[node][i].first});
                }
            }
        }
        timenode[0]=0;
        int ma=-1;
        for(int i=0;i<n+1;i++){
            if(timenode[i]==INT_MAX){
                return -1;
            }
            ma = max(ma,timenode[i]);
        }
        return ma;
    }
};