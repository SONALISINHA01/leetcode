class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> vowelprefix(n, 0);
        int sz = words[0].size();
        sz--;
        if ((words[0][0] == 'a' || words[0][0] == 'e' || words[0][0] == 'i' ||
             words[0][0] == 'o' || words[0][0] == 'u') &&
            (words[0][sz] == 'a' || words[0][sz] == 'e' ||
             words[0][sz] == 'i' || words[0][sz] == 'o' ||
             words[0][sz] == 'u')) {
            vowelprefix[0]++;
        }
        for (int i = 1; i < n; i++) {
            vowelprefix[i] = vowelprefix[i - 1];
            sz = words[i].size();
            sz--;
            if ((words[i][0] == 'a' || words[i][0] == 'e' ||
                 words[i][0] == 'i' || words[i][0] == 'o' ||
                 words[i][0] == 'u') &&
                (words[i][sz] == 'a' || words[i][sz] == 'e' ||
                 words[i][sz] == 'i' || words[i][sz] == 'o' ||
                 words[i][sz] == 'u')) {
                vowelprefix[i]++;
            }
        }
        vector<int> ans;
        for(int i=0;i<m;i++){
            int a = queries[i][0];
            int b = queries[i][1];
            int sum =0;
            if(a>0){
                sum -=vowelprefix[a-1];
            }
            sum+=vowelprefix[b];
            ans.push_back(sum);
        }
        return ans;
    }
};