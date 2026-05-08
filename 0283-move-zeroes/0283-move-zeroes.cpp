// Move Zeroes — O(n) Two Pointers In-Place
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[insertPos]);
                insertPos++;
            }
        }
    }
};