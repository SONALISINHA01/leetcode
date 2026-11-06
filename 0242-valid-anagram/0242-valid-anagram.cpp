class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 =s.size();
        vector<int> a1(26,0);
        int n2 =t.size();
        vector<int> a2(26,0);
        if(n1!=n2)return false;
        for(int i=0;i<n1;i++){
            a1[s[i]-'a']++;
            a2[t[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a1[i]!=a2[i]){
                return false;
            }
        }
        return true;
    }
};