class Solution {
public:
    bool judgeCircle(string moves) {
        int hori=0,veri=0;
        int n = moves.size();
        for(int i =0;i<n;i++){
            if(moves[i]=='L'){
                hori-=1;
            }else if(moves[i]=='R'){
                hori+=1;
            }else if(moves[i]=='U'){
                veri-=1;
            }else{
                veri+=1;
            }
        }
        if(veri==0 && hori==0)return true;
        return false;
    }
};