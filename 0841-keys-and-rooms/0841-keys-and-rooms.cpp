class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> locrooms(n, 1);

        // for (int i = 0; i < n; i++) {
        //     int sz = rooms[i].size();
        //     for (int j = 0; j < sz; j++) {
        //         locrooms[rooms[i][j]] = 1;
        //     }
        // }
        queue<int> q;
        for (int i = 0; i < rooms[0].size(); i++) {
            locrooms[rooms[0][i]] = 0;
            q.push(rooms[0][i]);
        }
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (int j = 0; j < rooms[i].size(); j++) {
                if (locrooms[rooms[i][j]] == 1) {
                    q.push(rooms[i][j]);
                    locrooms[rooms[i][j]] = 0;
                }
            }
        }
        locrooms[0]=0;
        for (int i = 0; i < n; i++) {
            if (locrooms[i] == 1) {
                return false;
            }
        }
        return true;
    }
};