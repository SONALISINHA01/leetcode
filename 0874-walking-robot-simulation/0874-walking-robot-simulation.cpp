class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int m = obstacles.size();
        set<pair<int,int>> ob;
        
        for(int i =0;i<m;i++){
            ob.insert({obstacles[i][0],obstacles[i][1]});
        }
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int curdir=0;
        int ans=0;
        int x=0,y=0;
        for(auto& cmd:commands){
            if(cmd==-1){
                curdir = (curdir+1)%4;
            }else if(cmd==-2){
                curdir=(curdir+3)%4;
            }else{
                for(int steps=0;steps<cmd;steps++){
                    int nextx = x+directions[curdir][0];
                    int nexty = y+directions[curdir][1];
                    if(ob.find({nextx,nexty})!=ob.end()){
                        break;
                    }
                    x=nextx;
                    y=nexty;
                }
            }
            ans = max(ans,(x*x+y*y));
        }
        return ans;
    }
};