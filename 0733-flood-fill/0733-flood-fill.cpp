class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        queue<pair<int,int>> q;
        int prevcolor = image[sr][sc];
        if(prevcolor == color) return image;
        image[sr][sc] = color;
        q.push({sr,sc});
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop();
                for(int k =0;k<4;k++){
                    if(i+dx[k]>=0 && j+dy[k]>=0 && i+dx[k]<n && j+dy[k]<m){
                        if(image[i+dx[k]][j+dy[k]]==prevcolor){
                            q.push({i+dx[k],j+dy[k]});
                            image[i+dx[k]][j+dy[k]] = color;
                        }
                    }
                }
            }
        }
        return image;
    }
};