class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for(int i =0;i<n;i++){
            adj[edges[i]].push_back(i);
        }
        vector<long long> sum(n,0);
        for(int i =0;i<n;i++){
            long long temp =0;
            for(int j =0;j<adj[i].size();j++){
                temp+=adj[i][j];
            }
            sum[i]=temp;
        }
        long long ans = -1;
        long long currmax=0;
        for(int i =0;i<n;i++){
            if(sum[i]>currmax){
                ans = i;
                currmax= sum[i];
            }
        }
        return ans;
    }
};