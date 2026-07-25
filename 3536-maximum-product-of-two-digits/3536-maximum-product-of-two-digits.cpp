class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        vector<int> freq(10,0);
        int sz= s.size();
        for(int i =0;i<sz;i++){
            freq[s[i]-'0']++;
        }
        int j =9, i =0;
        int ans=1;
        while(i<2&&j>=0){
            if(freq[j]>0){
                ans*=j;
                freq[j]--;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};