class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mp;
        mp['b']=0,mp['a']=0, mp['l']=0, mp['o']=0, mp['n']=0;
        for(int i=0;i<text.size();i++){
            if(mp.find(text[i])!=mp.end()){
                mp[text[i]]++;
            }
        }
        int ans=INT_MAX;
        for(auto &[key,val]:mp){
            if(key=='l'|| key=='o'){
                ans=min(ans,val/2);
            }else{
                ans = min(ans,val);
            }
        }
        return ans;
    }
};