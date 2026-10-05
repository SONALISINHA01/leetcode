class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> state(n,0);
        vector<int> entry(n,-1);
        int ans =-1;
        for(int i =0;i<n;i++){
            if(entry[i]!=-1 || state[i]!=0){
                continue;
            }
            int curr= i;
            int timer =0;
            while(edges[curr]!=-1 && state[curr]==0){
                entry[curr]=timer;
                timer++;
                state[curr]=1;
                curr= edges[curr];
            }
            if(edges[curr]!=-1 && state[curr]==1){
                ans = max(ans,timer-entry[curr]);
            }
            curr=i;
            while(curr!=-1&& state[curr]==1){
                state[curr]=2;
                curr= edges[curr];
            }

        }
        return ans;
    }
};