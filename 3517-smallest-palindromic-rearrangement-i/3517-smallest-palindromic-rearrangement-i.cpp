class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(int i =0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        string ans="";
        char mid =0;
        for(int i =0;i<26;i++){
            int a = freq[i]/2;
            if(freq[i]%2==1){
                mid = i +'a';
            }
            while(a--){
                ans +=( i+'a' );
            }
        }
        string rev = ans;
        reverse(rev.begin(),rev.end());
        if(mid)ans+= mid;
        ans+=rev;
        return ans;
    }
};