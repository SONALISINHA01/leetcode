class Solution {
public:
    int atMostKOdds(vector<int>& nums, int k){
        int n = nums.size();
        int si = 0, ei = 0;
        int oddCount = 0;
        int subarraycount = 0;

        while(ei < n){
            if(nums[ei++] % 2 == 1) oddCount++;

            while(oddCount > k){
                if(nums[si++] % 2 == 1) oddCount--;
            }

            subarraycount += ei - si;
        }
        return subarraycount;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostKOdds(nums, k) - atMostKOdds(nums, k - 1);
    }
};
