class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        if(n==1)return s;
        if(n==2){
            if(s[0]==s[1]){
                return s;
            }
            else{
                string g = "";
                g+=s[0];
                return g;
            }
        }
        //center expansion approach 
        int ans =1;
        int idi=0,idj=0;
        //odd index
        for(int i=1;i<n-1;i++){
            int j =i-1,k=i+1;
            while(j>=0 && k<n && s[j]==s[k]){
                if(ans<k-j+1){
                    ans=max(ans,k-j+1);
                    idi= j;
                    idj = k;
                }
                j--;
                k++;
            }
        }
        //even index
        for(int i =0;i<n-1;i++){
            if(s[i]==s[i+1]){
                if(ans<2){
                    ans=max(ans,2);
                    idi= i;
                    idj = i+1;
                }
                int j =i-1,k=i+2;
                while(j>=0 && k<n && s[j]==s[k]){
                    if(ans<k-j+1){
                        ans=max(ans,k-j+1);
                        idi= j;
                        idj = k;
                    }
                    j--;
                    k++;
                }
            }
        }
        return s.substr(idi,ans);

    }
};