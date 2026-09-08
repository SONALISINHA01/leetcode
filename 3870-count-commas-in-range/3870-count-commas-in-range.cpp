class Solution {
public:
    int countCommas(int n) {
        string s = to_string(n);
        int sz = s.size();
        if(sz<4)return 0;
        int comma = sz/3;
        int diff=0;
        if(comma>0) diff = n-1000+1;
        return diff;
    }
};