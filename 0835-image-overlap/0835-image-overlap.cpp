class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> a,b;
        int n=img1.size(),m = img1[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(img1[i][j]==1){
                    a.push_back({i,j});
                }
                if(img2[i][j]==1){
                    b.push_back({i,j});
                }
            }
        }
        int asz= a.size(), bsz =b.size();
        map<pair<int,int>,int> trial;
        for(int i =0;i<asz;i++){
            for(int j =0;j<bsz;j++){
                trial[{a[i][0]-b[j][0], a[i][1]-b[j][1]}]++;
            }
        }
        int ans =0;
        for(auto &an:trial){
            ans=max(ans,an.second);
        }
        return ans;
    }
};