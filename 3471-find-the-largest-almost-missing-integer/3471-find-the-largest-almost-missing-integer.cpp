class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(51, 0);

        // Count how many windows contain each number
        for (int i = 0; i <= n - k; i++) {
            vector<bool> seen(51, false);

            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }

            for (int x = 0; x <= 50; x++) {
                if (seen[x])
                    freq[x]++;
            }
        }

        // Find largest number appearing in exactly one window
        for (int x = 50; x >= 0; x--) {
            if (freq[x] == 1)
                return x;
        }

        return -1;
    }
};