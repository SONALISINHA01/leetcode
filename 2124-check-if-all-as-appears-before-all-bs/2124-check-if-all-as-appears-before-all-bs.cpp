class Solution {
public:
    bool checkString(string s) {
        bool bappeared = false;
        for(int i =0;i<s.size();i++){
            if(bappeared){
                if(s[i]=='a'){
                    return false;
                }
            }
            if(s[i]=='b'){
                bappeared=true;
            }
        }
        return true;
    }
};