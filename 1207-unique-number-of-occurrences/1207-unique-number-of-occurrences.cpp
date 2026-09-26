class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        map<int,int> ans;
        for(auto [key,value]:mp){
            ans[value]++;
            if(ans[value]>1){
                return false;
            }
        }
        return true;
    }
};