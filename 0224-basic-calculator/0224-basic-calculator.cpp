class Solution {
public:
    int ind=0;
    int recur(string& s){
        int n = s.size();
        int num=0;
        bool sign = true;
        long long dig=0;
        for(int i=ind;i<n;i++){
            if(s[i]==' '){
                continue;
            }
            if(s[i]==')'){
                if(sign){
                   num+=dig; 
                }else{
                    num-=dig;
                }
                dig=0;
                ind=i+1;
                return num;
            }else if(s[i]=='('){
                if(sign){
                   num+=dig; 
                }else{
                    num-=dig;
                }
                dig=0;
                ind = i+1;
                if(sign){
                    num+=recur(s);
                }
                else{
                    num-=recur(s);
                    sign = true;
                }
                i =ind-1;
            }else if(s[i]=='+'){
                if(sign){
                   num+=dig; 
                }else{
                    num-=dig;
                }
                dig=0;
                sign=true;
            }else if(s[i]=='-'){
                if(sign){
                   num+=dig; 
                }else{
                    num-=dig;
                }
                dig=0;
                sign= false;
            }else{
                dig=dig*10 + (s[i]-'0');
            }
        }
        if(sign){
            num+=dig; 
        }else{
            num-=dig;
        }
        dig=0;
        return num;
    }
    int calculate(string s) {
        return recur(s);
    }
};