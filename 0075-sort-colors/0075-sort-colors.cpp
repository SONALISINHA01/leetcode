class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int pt0=-1,itr = 0,pt2 =n-1;
        while(itr<=pt2){
            if(nums[itr]==0){
                swap(nums[++pt0],nums[itr]);
                itr++;
            }
            else if(nums[itr]==2){
                swap(nums[pt2],nums[itr]);
                pt2--;
            }
            else{
                itr++;
            }

        }
    }
};