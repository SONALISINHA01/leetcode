class Solution {
public:
    int maxDistance(string moves) {
        int hor=0,ver=0;
        int extra=0;
        for(int i =0;i<moves.size();i++){
            if(moves[i]=='U'){
                ver++;
            }else if(moves[i]=='D'){
                ver--;
            }else if(moves[i]=='L'){
                hor++;
            }else if(moves[i]=='R'){
                hor--;
            }else{
                extra++;
            }
        }
        // cout<<"hor: "<<hor<<" ver: "<<ver<<" extra:"<<extra<<endl;
        return (abs(hor)+abs(ver)+abs(extra));
    }
};