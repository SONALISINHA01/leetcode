class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> freq(256, 0);
        int count = n;
        for (int i = 0; i < n; i++) {
            freq[s1[i]]++;
        }
        int st = 0, en = 0;
        while (en < m) {
            freq[s2[en]]--;
            if (freq[s2[en]] >= 0) {
                count--;
            }
            if (count == 0) {

                while (count == 0) {
                    if (en - st + 1 == n) { // we need to check at every shrink if whether the valid window appeared maybe the valid window is from 3 to 6 so if we dont check it here while shrinking it will be checked from 0 to 6 and that will definitely fail.
                        return true;
                    }
                    freq[s2[st]]++;
                    if (freq[s2[st]] > 0) {
                        count++;
                    }
                    st++;
                }
            }
            en++;
        }
        return false;
    }
};