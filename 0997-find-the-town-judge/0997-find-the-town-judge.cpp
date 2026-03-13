class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0) return 1;
        vector<int> trusting(n+1);
        vector<int> gettingtrusted(n+1);
        int m =trust.size();
        for(int i=0;i<m;i++){
            trusting[trust[i][0]]++;
            gettingtrusted[trust[i][1]]++;
        }
        for(int i=0;i<n+1;i++){
            if(trusting[i]==0 && gettingtrusted[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};