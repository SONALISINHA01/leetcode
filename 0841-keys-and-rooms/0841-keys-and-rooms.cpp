class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<int> locrooms(n,1);

        queue<int> q;

        int sz  = rooms[0].size();
        locrooms[0]=0;
        for(int i =0;i<sz;i++){
            q.push(rooms[0][i]);
            locrooms[rooms[0][i]]=0;
        }

        while(!q.empty()){

            int key = q.front();
            q.pop();
            int sze = rooms[key].size();

            for(int i=0;i<sze;i++){
                if(locrooms[rooms[key][i]]==1){
                    q.push(rooms[key][i]);
                    locrooms[rooms[key][i]]=0;
                }
            }
        }
        for(int i =0;i<n;i++){
            if(locrooms[i]==1){
                return false;
            }
        }
        return true;
    }
};