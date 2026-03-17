class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i =0, j=0;
        int ans =0;
        map<int,int> mp;
        int temp=0;
        while(j<n){
            mp[fruits[j]]++;
            j++;
            temp++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                temp--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};