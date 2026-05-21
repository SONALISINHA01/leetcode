class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        for(int i=0;i<arr1.size();i++){
            string s = to_string(arr1[i]);
            int sz =s.size();
            for(int j = 1;j<=sz;j++){
                st.insert(s.substr(0,j));
            }
        }
        int ans =0;
        for(int i =0;i<arr2.size();i++){
            string p= to_string(arr2[i]);
            int sz = p.size();
            for(int j=1;j<=sz;j++){
                string sub = p.substr(0,j);
                if(st.find(sub)!=st.end()){
                    ans= max(ans,j);
                }
            }
        }
        return ans;
    }
};