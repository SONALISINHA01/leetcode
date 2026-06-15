class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int> pq;
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;

            // WRONG:
            // if(mp[nums[i]]==1){
            //     pq.push(nums[i]);
            // }

            // # Push every occurrence
            pq.push(nums[i]);
        }

        // while (!pq.empty() && mp[pq.top()] == 0) {
        //     pq.pop();
        // }

        ans.push_back(pq.top());

        for (int i = k; i < n; i++) {

            // WRONG:
            // if(pq.top()==nums[i]){
            //
            // }else{
            //     mp[nums[i-k]]--;
            //     mp[nums[i]]++;
            //     if(mp[nums[i]]==0){
            //         pq.push(nums[i]);
            //     }
            // }

            // # Always update window
            mp[nums[i - k]]--;
            mp[nums[i]]++;

            // # Push every incoming element
            pq.push(nums[i]);

            while (!pq.empty() && mp[pq.top()] == 0) {
                pq.pop();
            }

            ans.push_back(pq.top());
        }

        return ans;
    }
};