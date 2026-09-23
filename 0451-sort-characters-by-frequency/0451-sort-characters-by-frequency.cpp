class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        vector<int> freq(256,0);
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        vector<pair<int,char>> ans;
        for(int i=0;i<256;i++){
            if(freq[i]>0){
                ans.push_back({freq[i], i});
            }
        }
        sort(ans.begin(),ans.end(),[](const pair<int,char> &a,const pair<int,char> &b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            return a.second<b.second;
        });
        string an="";
        for(int i=0;i<ans.size();i++){
            while(ans[i].first--){
                an+=ans[i].second;
            }
        }
        return an;
    }
};