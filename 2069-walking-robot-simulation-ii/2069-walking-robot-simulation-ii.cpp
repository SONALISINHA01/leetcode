class Robot {
public:
    vector<int> pos={0,0};
    int dir=0;
    vector<vector<int>> dirco={{1,0},{0,1},{-1,0},{0,-1}};
    int w=0,h=0;
    int per =0;
    Robot(int width, int height) {
        h= height;
        w= width;
        per = 2*(h+w) - 4;
    }
    
    void step(int num) {
        if(per==0) return;
        num %=per;
        int i =0;
        if(num == 0 && pos[0]==0 && pos[1]==0){
            dir = 3;
            return;
        }
        while(i<num){
            int nextx = pos[0]+dirco[dir][0];
            int nexty = pos[1]+dirco[dir][1];
            if(nextx >=w || nexty >= h || nextx<0||nexty<0){
                dir = (dir+1)%4;
                continue;
            }else{
                pos[0] = nextx;
                pos[1] = nexty; 
                i++;
            }
        }
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        if(dir==0){
            return "East";
        }else if(dir==1){
            return "North";
        }else if(dir == 2){
            return "West";
        }
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */