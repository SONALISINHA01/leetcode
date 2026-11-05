class Solution {
public:
    bool isPalindrome(string s) {
        string alpha="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' ' or s[i]==',' or s[i]==':')continue;
            if((s[i]-'a'>=0 && s[i]-'a'<26 )|| (s[i]-'A'>=0 && s[i]-'A'<26 or ((s[i]-'0')>=0) && (s[i]-'0'<=9)))
                alpha+=tolower(s[i]);
             
        }
        int n = alpha.size();
        int i=0, j= n-1;
        while(i<j){
            if(alpha[i]!=alpha[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
};