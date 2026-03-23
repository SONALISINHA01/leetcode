class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &temp, int n, int k){
        if(temp.size()==k){
            ans.push_back(temp);//help
            return; 
        }
        int m = temp.size();
        for(int i =temp[m-1]+1;i<=n;i++){
            if(m<k){
                temp.push_back(i);
                solve(temp,n,k);
                temp.pop_back();//help
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        for(int i=1;i<=n;i++){
            vector<int> temp;
            temp.push_back(i);
            solve(temp,n,k);
            //ans.push_back(temp); help taken 
        }
        return ans; 
    }
};