class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;
        map<char,int> mp;
        int l =0;
        int ans =0;
        while(i<n){
            mp[s[i]]++;
            if(mp[s[i]]>1){
                while(mp[s[i]]>1){
                    mp[s[l]]--;
                    l++;
                }
            }
            ans = max(ans, i-l+1);
            i++;
        }
        return ans;
    }
};