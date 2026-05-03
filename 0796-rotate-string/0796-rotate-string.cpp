class Solution {
public:
    bool rotateString(string s, string goal) {
        if(!(s.size()==goal.size())){
            return false;
        }
        string concat = s+s;
        if(concat.find(goal) != -1){
            return true;
        }
        return false;
    }
};