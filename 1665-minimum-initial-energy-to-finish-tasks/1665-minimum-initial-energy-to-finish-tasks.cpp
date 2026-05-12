class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(),tasks.end(),[](const vector<int> &a , const vector<int> &b){
            // if(a[1]==b[1]){
            //     return a[0]>b[0];
            // }
            // return b[1]<a[1];
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int  req=0;
        int added=0;
        for(int i=0;i<n;i++){
            if(req<tasks[i][1]){
                added +=tasks[i][1]-req;
                req = tasks[i][1];
            }
            req -= tasks[i][0];
        }
        return added;
    }
};