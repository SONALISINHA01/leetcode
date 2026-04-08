class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0])return a[1]>b[1];//this will return whichever is larger when first element is equal;
            return a[0]<b[0];//this will return whichever is smaller
        });
        vector<int> lis;
        for(auto &h:envelopes){
            int x =h[1];
            auto it = lower_bound(lis.begin(), lis.end(),x);
            if(it==lis.end())lis.push_back(x);
            else *it=x;
        }
        return lis.size();
    }
};