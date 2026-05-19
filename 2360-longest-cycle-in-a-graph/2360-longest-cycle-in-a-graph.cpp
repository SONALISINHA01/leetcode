class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int ans =-1;
        int time =1;
        vector<int> timevisited(edges.size());
        for(int i =0;i<edges.size();i++){
            if(timevisited[i]) continue;
            const int starttime = time;
            int u =i;
            while(u!=-1 && !timevisited[u]){
                timevisited[u]=time++;
                u = edges[u];
            }
            if(u!=-1 && timevisited[u]>=starttime){
                ans = max(ans,time- timevisited[u]);
            }
        }
        return ans;
    }
};