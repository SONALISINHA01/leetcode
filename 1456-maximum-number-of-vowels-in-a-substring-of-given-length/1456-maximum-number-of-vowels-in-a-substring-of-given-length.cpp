class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int ei =0,si =0,count=0;
        int ans=0;
        while(ei<n){
            if(s[ei]== 'a' || s[ei]== 'e' || s[ei]== 'i' || s[ei]== 'o' || s[ei]== 'u'){
                count++;
            }
            if(ei-si>=k){
                if(s[si]== 'a' || s[si]== 'e' || s[si]== 'i' || s[si]== 'o' || s[si]== 'u'){
                    count--;
                }
                si++;
            }
            ei++;
            ans=max(ans,count);
        }
        return ans;
    }
};