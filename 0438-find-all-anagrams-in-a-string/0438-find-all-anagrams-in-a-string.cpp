class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n= s.size(), m = p.size();
        vector<int> freq(256,0);
        for(int i =0;i<m;i++){
            freq[p[i]]++;
        }
        int count = m;
        int en =0, st =0;
        vector<int> ans;
        while(en<n){
            freq[s[en]]--;
            if(freq[s[en]]>=0){
                count--;
            }
            while(count==0){
                if(en-st+1 == m){
                    ans.push_back(st);
                }
                freq[s[st]]++;
                if(freq[s[st]]>0){
                    count++;
                }
                st++;
            }
            en++;
        }
        return ans ;
    }
};