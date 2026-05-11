class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            deque<int> q;
            while(nums[i]>0){
                q.push_front(nums[i]%10);
                nums[i]=nums[i]/10;
            }
            while(!q.empty()){
                ans.push_back(q.front());
                q.pop_front();
            }
        }
        return ans;
    }
};