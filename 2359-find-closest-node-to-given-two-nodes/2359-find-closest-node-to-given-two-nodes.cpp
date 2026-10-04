class Solution {
public:
    void bfs(vector<int> &edges, int n1,vector<int> &dist){
        dist[n1]=0;
        queue<int> q;
        q.push(n1);
        int trav=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr =q.front();q.pop();
                if(edges[curr]!= -1 && dist[edges[curr]]==INT_MAX){
                    q.push(edges[curr]);
                }
                dist[curr]=trav;
            }
            trav++;
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> distn1(n,INT_MAX),distn2(n,INT_MAX);
        bfs(edges,node1,distn1);
        bfs(edges,node2,distn2);
        int cont = INT_MAX;
        int ans =-1;
        for(int i =0;i<n;i++){
            int ma = max(distn1[i],distn2[i]);
            if(ma<cont){
                ans = i;
                cont = ma;
            }
        }
        return ans;
    }
};