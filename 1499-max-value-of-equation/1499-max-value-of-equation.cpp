class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        priority_queue<pair<int, int>> pq;        
        pq.push({points[0][1]-points[0][0],points[0][0]});
        for(int i =1;i<n;i++){
            int xj = points[i][0], yj = points[i][1];
            int xi = points[i-1][0],yi=points[i-1][1];
            while(!pq.empty() && xj-pq.top().second>k){
                pq.pop();
            }
            if(!pq.empty())ans = max(ans,xj+yj + pq.top().first);
            pq.push({yj-xj,xj});
        }
        return ans;
    }
};