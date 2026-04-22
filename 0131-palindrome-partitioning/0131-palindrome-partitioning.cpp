class Solution {
public:
    vector<vector<string>> ans;
    bool ispalindrome(string s){
        int m = s.size();
        int i =0, j = m-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    void solve(string s , int n , int i , vector<string>& temp){
        if(i >=n){
            ans.push_back(temp);
            return;
        }
        string str = "";
        for(int j = i; j<n;j++){
            str+=s[j];
            if(ispalindrome(str)){
                temp.push_back(str);
                solve(s,n,j+1,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string> temp;
        solve(s,n,0,temp);
        return ans;
    }
};