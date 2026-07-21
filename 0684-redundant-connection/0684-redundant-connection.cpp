class DSU{
    public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i =0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findpar(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = findpar(parent[u]);
    }
    void unio(int u,int v){
        int paru = findpar(u);
        int parv = findpar(v);
        if(paru == parv){
            return ;
        }
        if(rank[paru]<rank[parv]){
            parent[paru]=parv;
        }else if(rank[paru]>rank[parv]){
            parent[parv]=paru;
        }else{
            parent[paru]=parv;
            rank[parv]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU* dsu = new DSU(n);
        for(int i=0;i<n;i++){
            int fire = edges[i][0];
            int sece = edges[i][1];
            int parf = dsu->findpar(fire);
            int pars = dsu->findpar(sece);
            if(parf==pars){
                return {fire,sece};
            }else{
                dsu->unio(fire,sece);
            }
        }
        return {};
    }
};