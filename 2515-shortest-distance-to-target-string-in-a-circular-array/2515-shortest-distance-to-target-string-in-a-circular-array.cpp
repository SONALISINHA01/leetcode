class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        
        if(words[startIndex] == target) return 0;

        int ans = INT_MAX;

        // forward
        for(int step = 1; step < n; step++) {
            int idx = (startIndex + step) % n;
            if(words[idx] == target) {
                ans = min(ans, step);
                break;
            }
        }

        // backward
        for(int step = 1; step < n; step++) {
            int idx = (startIndex - step + n) % n;
            if(words[idx] == target) {
                ans = min(ans, step);
                break;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};