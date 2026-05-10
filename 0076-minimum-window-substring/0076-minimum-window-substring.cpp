class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> freq(128,0);
        for(int i=0;i<m;i++){
            freq[t[i]]++;
        }
        int count = m;
        int ans = INT_MAX;
        int en =0, st=0;
        int start =0;
        while(en<n){
            freq[s[en]]--;
            if(freq[s[en]]>=0){
                count--;
            }
            while(count==0){
                if(ans>(en-st+1)){
                    ans = (en-st+1);
                    start = st;
                }
                
                freq[s[st]]++;
                if(freq[s[st]]>0){
                    count++;
                }
                st++;
            }
            en++;
        }
        if(ans==INT_MAX)return "";
        return s.substr(start,ans);
    }
};