class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rightsum=0;
        for(int i=0;i<n;i++){
            rightsum+=nums[i];
        }
        int leftsum=0;
        rightsum-=nums[0];
        if(leftsum==rightsum)return 0;
        for(int i=1;i<n;i++){
            rightsum-=nums[i];
            leftsum+=nums[i-1];
            if(rightsum==leftsum){
                return i;
            }
        }
        return -1;
    }
};