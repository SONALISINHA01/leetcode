class DSU{
    public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++){
            parent[i]=i;
        }
    }
    int findpar(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=findpar(parent[u]);
    }
    void unio(int u,int v){
        int paru = findpar(u);
        int parv = findpar(v);
        if(paru == parv){
            return;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU* dsu = new DSU(n);
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                if(isConnected[i][j]){
                    dsu->unio(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dsu->parent[i]==i){
                ans++;
            }
        }
        return ans;
    }
};