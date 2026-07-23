class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0,count2=0;
        int candi1=-1,candi2=-1;
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i]!=candi2){
                count1++;
                candi1 = nums[i];
            }else if(count2 == 0 && nums[i]!=candi1){
                count2++;
                candi2 = nums[i];
            }else if(nums[i]==candi1){
                count1++;
            }else if(nums[i]==candi2){
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        int freq1 = 0, freq2=0;
        for(int i =0;i<n;i++){
            if(candi1==nums[i]){
                freq1++;
            }else if(candi2 == nums[i]){
                freq2++;
            }
        }
        int req  = (n/3);
        vector<int> ans;
        if(freq1>req){
            ans.push_back(candi1);
        }
        if(freq2>req){
            ans.push_back(candi2);
        }
        return ans;
    }
};