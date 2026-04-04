class Solution {
public:
    string decodeCiphertext(string encodedtext, int r) {
        int n = encodedtext.size();
        int m = n/r;
        vector<vector<char>> mat(r,vector<char>(m));
        int k=0;
        for(int i =0;i<r;i++){
            for(int j =0;j<m;j++){
                mat[i][j]=encodedtext[k];
                k++;
            }
        }
        string ans;
        int j =0;
        while(j<m){
            for(int i =0;i<r;i++){
                if(i+j<m)ans+=mat[i][i+j];
            }
            j++;
        }
        int sz= ans.size();
        for(int z=sz-1;z>=0;z--){
            if(ans[z]==' '){
                ans.pop_back();
            }else{
                break;
            }
        }
        return ans;
    }
};