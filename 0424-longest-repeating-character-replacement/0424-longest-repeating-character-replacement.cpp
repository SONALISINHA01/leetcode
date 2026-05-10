class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans =0;
        for(int i =0;i<26;i++){
            char ch = 'A'+i;
            int en =0,st=0;
            int temp = k;
            while(en<n){
                if(s[en]==ch){
                    en++;
                }else{
                    if(temp>0){
                        temp--;
                        en++;
                    }else{
                        while(temp<=0){
                            if(s[st]!=ch){
                                temp++;
                                st++;
                            }else{
                                st++;
                            }
                        }
                    }
                }
                ans=max(ans, en-st);
            }
        }
        return ans ;
    }
};