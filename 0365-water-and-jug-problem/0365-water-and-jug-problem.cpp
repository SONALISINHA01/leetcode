class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(target>x+y){
            return false;
        }
        queue<pair<int,int>> q;
        q.push({0,0});

        set<pair<int,int>> achievedstates;
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            if(a+b==target){
                return true;
            }
            if(achievedstates.find({a,b})!=achievedstates.end()){
                continue;
            }
            achievedstates.insert({a,b});
            q.push({a,0});
            q.push({0,b});
            q.push({x,b});
            q.push({a,y});
            int fromatob = min(a,y-b);
            if(fromatob>=0){
                q.push({a-fromatob,b+fromatob});
            }
            int frombtoa = min(x-b,b);
            if(frombtoa>=0){
                q.push({a+frombtoa,b-frombtoa});
            }
        }
        return false;
    }
};