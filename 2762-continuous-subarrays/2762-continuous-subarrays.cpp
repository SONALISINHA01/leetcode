class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        multiset<int> s;
        int i =0,j=0;
        long long count=0;
        while(i<n){
            s.insert(nums[i]);
            int lo = *s.begin();
            int ma = *s.rbegin();
            while(abs(lo-ma)>2 && j<n){
                s.erase(s.find(nums[j]));
                lo = *s.begin();
                ma = *s.rbegin();
                j++;
            }
            i++;
            count+=(i-j);
        }
        return count;
    }
};