class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gastank =0;
        int totalfuel=0;
        int need=0;
        int startidx=0;
        for(int i =0;i<gas.size();i++){
            totalfuel += gas[i];
            need += cost[i];
            gastank+=(gas[i]-cost[i]);
            if(gastank<0){
                startidx= i+1;
                gastank =0;
            }
        }
        if(totalfuel>=need) return startidx;
        return -1;
    }
};