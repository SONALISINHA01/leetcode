class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> words;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(!temp.empty()){
                    words.push_back(temp);
                    temp="";
                }
            }else{
                temp+=s[i];
            }
        }
        if(!temp.empty()){
            words.push_back(temp);
        }
        int n = words.size();
        string last = words[n-1];
        return last.size();
    }
};