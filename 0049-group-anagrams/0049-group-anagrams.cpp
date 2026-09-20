class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> keeper;
        int n = strs.size();
        for(int i =0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            keeper[temp].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto [key,vec]:keeper){
            ans.push_back(vec);
        }
        return ans;
    }
};