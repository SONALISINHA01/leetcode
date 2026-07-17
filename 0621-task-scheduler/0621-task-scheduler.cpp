class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto &it:tasks){
            freq[it-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0)pq.push(freq[i]);
        }
        int time=0;
        queue<int> q;
        while(!pq.empty()){
            int cycle = n+1;
            int taskcount=0;
            while(cycle-- && !pq.empty()){
                if(pq.top()>1){
                    q.push(pq.top()-1);
                    pq.pop();
                }else{
                    pq.pop();
                }
                taskcount++;
            }
            while(!q.empty()){
                pq.push(q.front());
                q.pop();
            }
            if(pq.empty()){
                time+=taskcount;
            }else{
                time+=n+1;
            }
        }
        return time;
    }
};