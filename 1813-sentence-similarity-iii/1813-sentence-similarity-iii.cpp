class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> wb1,wb2;
        string temp1,temp2;
        int n = s1.size(),m=s2.size();
        if(n>m){
            swap(n,m);
            swap(s1,s2);
        }
        for(int i=0;i<n;i++){
            if(s1[i]==' '&& temp1.size()!=0){
                wb1.push_back(temp1);
                temp1="";
            }else{
                temp1+=s1[i];
            }
        }
        for(int i=0;i<m;i++){
            if(s2[i]==' '&&temp2.size()!=0){
                wb2.push_back(temp2);
                temp2="";
            }else{
                temp2+=s2[i];
            }
        }
        if (!temp1.empty()) wb1.push_back(temp1);
        if (!temp2.empty()) wb2.push_back(temp2);
        n = wb1.size(),m = wb2.size();
        int i =0,j=1;
        while(i<n&&i<m && wb1[i]==wb2[i]){
            i++;
        }
        int cj=0;
        while(n-j>=i && m-j>=i && wb1[n-j]==wb2[m-j]){
            j++;
            cj++;
        }
        if(i+cj == n){
            return true;
        }return false;
    }
};