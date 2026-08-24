class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(),env.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int> lis;
        int ans = 0;
        for(int i =0;i<env.size();i++){
            int temp = env[i][1];
            auto it = lower_bound(lis.begin(),lis.end(),temp);
            if(it==lis.end()){
                lis.push_back(temp);
            }
            else{
                *it = temp;
            }
        }
        return lis.size();
    }
};