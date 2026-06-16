class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string normal="";
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                if(normal.size()>0){
                    normal.pop_back();
                }
            }else if(s[i]=='#'){
                normal+=normal;
            }else if(s[i]=='%'){
                reverse(normal.begin(),normal.end());
            }else{
                normal+=s[i];
            }
        }
        return normal;
    }
};