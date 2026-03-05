class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        map<char,int> mp;
        for(int i =0;i<n;i++){
            mp[s[i]]++;
        }
        int odd=0;
        int ans=0;
        for(auto [ch,nu]:mp){
            if(nu%2==0){
                ans+=nu;
            }else if(nu%2!=0 && nu!=1){
                ans+=(nu-1);
                odd++;
            }else{
                odd++;
            }
        }
        if(odd>0){
            ans++;
        }
        return ans;
    }
};