class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);// number of incoming directed edges
        for(int i =0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int temp = q.front();
            ans.push_back(temp);
            q.pop();
            for(auto &it: adj[temp]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size() == adj.size()){
            vector<int> revans(ans.size());
            for(int i =0;i<ans.size();i++){
                revans[i]=ans[ans.size()-i-1];
            }
            return revans;
        }
        vector<int> emp;
        return emp;
    }
};