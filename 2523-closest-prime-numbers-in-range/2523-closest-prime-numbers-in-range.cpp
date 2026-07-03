class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = right;
        vector<bool> prime(n + 1, false);
        prime[0] = true;
        prime[1] = true;

        for (int i = 2; i * i <= n; i++) {
            if (!prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = true;
                }
            }
        }

        vector<pair<int, int>> ans;

        for (int i = left; i <= right; i++) {
            if (!prime[i]) {
                int j = i + 1;
                while (j <= right && prime[j]) {
                    j++;
                }
                if (j > right) break;
                ans.push_back({i, j});
            }
        }

        int mi = INT_MAX;
        int x = -1, y = -1;

        for (int i = 0; i < ans.size(); i++) {
            if ((ans[i].second - ans[i].first) < mi) {
                mi = ans[i].second - ans[i].first;
                x = ans[i].first;
                y = ans[i].second;
            }
        }

        return {x, y};
    }
};