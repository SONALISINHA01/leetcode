class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int count =0;
        int n = nums.size();
        for(int i =0;i<n;i++){
            long long sum=0;
            for(int j =i;j<n;j++){
                sum += nums[j];
                long long la= sum%10;
                long long temp = sum;
                while(temp>9){
                    temp/=10;
                }
                long long st = temp;
                if(st==x && la==x){
                    // cout<<"when satisfied: "<<sum<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};