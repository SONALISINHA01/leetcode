class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128,0);
        for(auto c:t) freq[c]++;
        int minlen=INT_MAX, start=0;
        int count =t.size(), left =0;
        for(int right = 0;right<s.size();right++){
            if(freq[s[right]]>0)count--;
            freq[s[right]]--;
            while(count==0){
                if(right-left +1<minlen){
                    minlen = right-left+1;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0)count++;
                left++;
            }
        }
        if(minlen!=INT_MAX){
            return s.substr(start,minlen);
        }
        return "";
    }
};