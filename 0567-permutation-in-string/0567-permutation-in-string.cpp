class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<int> freq(256,0);
        int count = n;
        for(int i=0;i<n;i++){
            freq[s1[i]]++;
        }
        int st =0, en =0;
        while(en<m){
            freq[s2[en]]--;
            if(freq[s2[en]]>=0){
                count--;
            }
            if(count==0){
                
                    while(count==0){
                        if(en-st+1 == n){
                            return true;
                        }
                        freq[s2[st]]++;
                        if(freq[s2[st]]>0){
                            count++;
                        }
                        st++;
                    }
                
            }
            en++;
        }
        return false;
    }
};