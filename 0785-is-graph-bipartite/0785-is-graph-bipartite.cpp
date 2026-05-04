class Solution {
public:
    bool dfs(vector<vector<int>> &graph, int col, int othcol, vector<int>& colour,int i){
        if(colour[i]!=0){
            return colour[i]==col;
        }
        colour[i]=col;
        for(auto j:graph[i]){
            if(!dfs(graph,othcol,col,colour,j))return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n,0);
        for(int i=0;i<n;i++){
            if(colour[i]==0){
                if(!dfs(graph,1,2,colour,i)) return false;
            }
        }
        return true;
    }
};