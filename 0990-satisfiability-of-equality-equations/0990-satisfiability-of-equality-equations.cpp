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
    bool equationsPossible(vector<string>& eq) {
        parent=vector<int>(26,0);
        rank = vector<int>(26,0);
        for(int i =0;i<26;i++){
            parent[i]=i;
        }
        for(int i =0;i<eq.size();i++){
            if(eq[i][1]=='='){
                rankunion((eq[i][0]-'a'),(eq[i][3]-'a'));
            }
        }
        for(int i =0;i<eq.size();i++){
            if(eq[i][1]=='!'){
                int u = find((eq[i][0]-'a'));
                int v = find((eq[i][3]-'a'));
                if(u==v){
                    return false;
                }
            }
        }
        return true;
    }
};