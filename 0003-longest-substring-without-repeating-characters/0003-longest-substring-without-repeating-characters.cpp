class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int fir=0,sec=0;
        int n = s.size();
        int ans =0;
        vector<int> str(256,0);
        for(int i =0;i<n;i++){
            while(str[s[i]]!=0 && sec<n){
                str[s[sec]]--;
                sec++;
            }
            str[s[i]]++;
            ans=max(ans,(i-sec+1));
        }
        return ans;
    }
};