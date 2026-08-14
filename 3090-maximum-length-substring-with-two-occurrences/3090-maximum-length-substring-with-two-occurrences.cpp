class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int i = 0, k = 0;
        int ans = 0;
        while (i < s.size()) {
            freq[s[i] - 'a']++;
            while (freq[s[i] - 'a'] > 2) {
                freq[s[k] - 'a']--;
                k++;
            }
            ans = max(ans, i - k+1);
            i++;
        }
        return ans;
    }
};