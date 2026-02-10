class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        for(int i =0;i<n;i++){
            unordered_map<int,int> ev,od;
            int even =0, odd=0;
            for(int j =i;j<n;j++){
                if(nums[j]%2==0){
                    if(ev.find(nums[j])==ev.end()){
                        ev[nums[j]]++;
                        even++;
                    }
                }else{
                    if(od.find(nums[j])==od.end()){
                        od[nums[j]]++;
                        odd++;
                    }
                }
                if(odd==even){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};