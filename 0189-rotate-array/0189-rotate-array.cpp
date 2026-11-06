class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        vector<int> temp(n,-1);
        for(int i=n-k;i<n;i++){
            temp[i-(n-k)] = nums[i];
        }
        for(int i =0;i<n-k;i++){
            temp[i+k]=nums[i];
        }
        nums=temp;
    }
};