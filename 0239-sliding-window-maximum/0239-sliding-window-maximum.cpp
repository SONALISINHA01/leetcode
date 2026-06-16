class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for(int i =0;i<k;i++){
            while(!dq.empty() && dq.back()<nums[i]){
                dq.pop_back();
            }
            if(!dq.empty() && nums[i]>=dq.front()){
                dq.push_front(nums[i]);
            }else{
                dq.push_back(nums[i]);
            }
        }
        result.push_back(dq.front());
        for(int i=k;i<nums.size();i++){
            if(nums[i-k]==dq.front()){
                dq.pop_front();
            }
            while(!dq.empty() && dq.back()<nums[i]){
                dq.pop_back();
            }
            if(!dq.empty() && nums[i]>=dq.front()){
                dq.push_front(nums[i]);
            }else{
                dq.push_back(nums[i]);
            }
            result.push_back(dq.front());
        }
        return result;
    }
};