class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long planet =(1LL)*mass;
        for(int i =0;i<asteroids.size();i++){
            if(planet<asteroids[i]){
                return false;
            }
            planet+=asteroids[i];
        }
        return true;
    }
};