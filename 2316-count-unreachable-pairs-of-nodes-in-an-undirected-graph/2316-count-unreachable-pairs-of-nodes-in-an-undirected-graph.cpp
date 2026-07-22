class DSU{
    public:
    vector<int> parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
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
        }else if(rank[parv]<rank[paru]){
            parent[parv]=paru;
        }else{
            parent[parv]=paru;
            rank[paru]++;
        }
    }
};
class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        DSU* dsu=new DSU(n);
        for(int i=0;i<m;i++){
            dsu->unio(edges[i][0],edges[i][1]);
        }
        map<int,int> count;
        for(int i =0;i<n;i++){
            count[dsu->findpar(i)]++;
        }
        long long num = n;
        long long ans=0;
        for(auto &[key,value]:count){
            ans+=(1LL)*(value * (num-value));
            num -=value;
        }
        return ans;
    }
};