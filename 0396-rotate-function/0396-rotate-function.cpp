class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;      
        long long mulsum = 0;
        for(int i = 0; i < n; i++){
            mulsum += 1LL * i * nums[i];   
            sum += nums[i];
        }
        long long ans = mulsum; 
        for(int i = 0; i < n; i++){
            mulsum -= sum;
            mulsum += 1LL * n * nums[i];   
            ans = max(ans, mulsum);
        }
        return (int)ans;
    }
};