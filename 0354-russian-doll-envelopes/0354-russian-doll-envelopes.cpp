class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& en) {
        int n = en.size();
        sort(en.begin(),en.end(),[](vector<int>& a, vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        vector<int> lis;
        int ans =0;
        for(int i=0;i<n;i++){
            int temp=en[i][1];
            auto it = lower_bound(lis.begin(),lis.end(),temp);
            if(it==lis.end()){
                lis.push_back(temp);
            }else{
                *it = temp;
            }
        }
        return lis.size();
    }
};