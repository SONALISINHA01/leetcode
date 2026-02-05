class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int si=0,ei=0, count=0;
        vector<int> freq(128,0);
        int ans=0;
        while(ei<n){
            if(freq[s[ei]]==1)count++;
            freq[s[ei]]++;
            ei++;
            while(count == 1){
                if(freq[s[si]]==2)count--;
                freq[s[si]]--;
                si++;
            }
            ans=max(ans,ei-si);
        }
        return ans;
    }
};