class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        vector<int> upidx(26,-1);
        vector<int> lowidx(26,-1);
        for(int i =0;i<n;i++){
            if(word[i]-'A'>=0 && word[i]-'A'<26 && upidx[word[i]-'A']==-1){
                upidx[word[i]-'A']=i;
            }
        }
        for(int i =n-1;i>=0;i--){
            if(word[i]-'a'>=0 && word[i]-'a'<26 && lowidx[word[i]-'a']==-1){
                lowidx[word[i]-'a']=i;
            }
        }
        int ans =0;
        for(int i=0;i<26;i++){
            if(upidx[i]!=-1 && lowidx[i]!=-1 && (upidx[i]>lowidx[i])){
                ans++;
            }
        }
        return ans;
    }
};