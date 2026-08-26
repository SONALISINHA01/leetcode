class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0, j =0;
        int ansi=-1, ansj=-1;
        int len =INT_MAX;
        while(j<s.size()){
            if(s[j]=='1'){
                k--;
                while( k==0){
                    if((j-i+1)<len){
                        len = min(len, (j-i+1));
                        ansj = j;
                        ansi =i;
                    }else if((j-i+1)==len){
                        string first = s.substr(ansi,len);
                        string sec = s.substr(i,len);
                        if(sec<first){
                            ansj = j;
                            ansi =i;
                        }
                    }
                    if(s[i]=='1'){
                        k++;
                    }
                    i++;
                }
            }
            j++;
        }
        if(ansi==-1){
            return "";
        }
        return s.substr(ansi,len);
    }
};
