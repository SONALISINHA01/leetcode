class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        //hiiiiii babyyyyyyyyyyyyyyyyyyyyy
        vector<int> prefsum(n);//prefix sum vector
        prefsum[0]=nums[0];

        for(int i =1;i<n;i++){
            prefsum[i]=prefsum[i-1]+nums[i];
        }
        unordered_map<int,int> mp;

        int ans =0;
        vector<int> rem(n);//lolololololololoollooloolll
        // awww mera bechara babyyy
        // good job
        //love youuuuuu
        // i dont want thisss
        // when i had already made a different vector just to store this shit why did you delete thatt 
        // motherfuckerrr
        for(int i=0;i<n;i++){
            rem[i]=prefsum[i]%k;//lolololol
        }
        for(int i =0;i<n;i++){
        //remainder and processing while updating else mp map will contain information/value of all , same mistake you did in last problem too . Do  
            if(rem[i]<0){ rem[i]+=k;}//baby remainder kbhi negative hoga???
            if(rem[i]==0){
                ans++;
            }
            if(mp.find(rem[i])!=mp.end()){
                ans+=mp[rem[i]];
            }
            mp[rem[i]]++;
        }
        return ans;
    }
};
//done . signing off stay here you little brat