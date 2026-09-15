class Solution {
public:
    bool palinchecker(int i , int j , string s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;

    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        // thinking of centre expansion till we hit the length == k or already used char
        int lastused =-1;
        int ans =0;
        for(int i =k-1;i<n;i++){
            int u = i-k+1;
            while(u>=0 && u>lastused){
                if(palinchecker(u,i,s)){
                    lastused = i;
                    ans++;
                    break;
                }
                u--;
            }
        }
        return ans;
    }
};