class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void rankunion(int i,int j){
        int u = find(i);
        int y = find(j);
        if(u==y){
            return;
        }
        if(rank[u]>rank[y]){
            parent[y]=u;
        }else if(rank[y]>rank[u]){
            parent[u]=y;
        }else{
            parent[y]=u;
            rank[u]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& co) {
        if(co.size()<n-1){
            return -1;
        }
        parent=vector<int>(n,0);
        rank = vector<int>(n,0);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
        int extracabel=0;
        int connect=0;
        for(int i =0;i<co.size();i++){
                int u = find(co[i][0]);
                int v = find(co[i][1]);
                if(u==v){
                    extracabel++;
                }else{
                    rankunion(u,v);
                    connect++;
                }
        }
        int components = 0;
        for(int i = 0; i < n; i++){
            if(find(i) == i){
                components++;
            }
        }
        return components - 1;
    }
};