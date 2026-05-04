class Solution {
public:
    bool dfs(vector<vector<int>> &peep,vector<int> &colour, int col,int othcol, int i){
        if(colour[i]!=0){
            return colour[i]==col;
        }
        colour[i]=col;
        for(auto j:peep[i]){
            if(!dfs(peep,colour,othcol,col,j))return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> peep(n+1);
        for(int i =0;i<dislikes.size();i++){
            peep[dislikes[i][0]].push_back(dislikes[i][1]);
            peep[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> colour(n+1,0);
        for(int i=1;i<=n;i++){
            if(colour[i]==0){
                if(!dfs(peep,colour,1,2,i)) return false;
            }
        }
        return true;
    }
};