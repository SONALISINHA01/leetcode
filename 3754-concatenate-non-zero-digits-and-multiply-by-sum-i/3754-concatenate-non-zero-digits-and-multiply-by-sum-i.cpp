class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0){
            return 0;
        }
        string s = to_string(n);
        string ans;
        long long mul=0;
        for(int i =0;i<s.size();i++){
            if(s[i]!='0'){
                ans+=s[i];
                mul+=s[i]-'0';
            }

        }
        // cout<<ans<<" "<<mul;
        return (long long)stoi(ans)*(long long)mul;
        
    }
};