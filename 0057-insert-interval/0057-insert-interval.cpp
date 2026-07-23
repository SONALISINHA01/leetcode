class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({newInterval[0],newInterval[1]});
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int i =0;
        int  currst = intervals[i][0], curren = intervals[i][1];
        i++;
        while(i<intervals.size()){
            if(curren<intervals[i][0]){
                ans.push_back({currst,curren});
                currst = intervals[i][0];
                curren = intervals[i][1];
            }else{
                currst = min(currst,intervals[i][0]);
                curren = max(curren , intervals[i][1]);
            }
            i++;
        }
        ans.push_back({currst,curren});
        return ans;
    }
};