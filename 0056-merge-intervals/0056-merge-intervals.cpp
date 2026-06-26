class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inte) {
        sort(inte.begin(),inte.end());
        vector<vector<int>> ans;
        int st= inte[0][0],en = inte[0][1];
        for(int i =1;i<inte.size();i++){
            if(inte[i][0]<=en){
                en = max(en,inte[i][1]);
            }else{
                ans.push_back({st,en});
                st=  inte[i][0],en=inte[i][1];
            }
        }
        ans.push_back({st,en});
        return ans;
    }
};