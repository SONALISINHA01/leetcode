class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n =tasks.size();
        vector<long long> timereq(n+1,0);
        for(int i =0;i<n;i++){
            timereq[i+1]=timereq[i]+tasks[i];
        }
        vector<int> ans;
        int idx=0;
        long long done =0;
        for(int i =0;i<shifts.size();i++){
            int val = shifts[i];
            int en = n,st=0;
            int mid=0;
            long long target = timereq[idx]+done+shifts[i];
            if(target>=timereq[n]){
                ans.push_back(0);
                idx=0;
                done =0;
                continue;
            }
            while(st<=en){
                mid =(en-st)/2 +st;
                if(timereq[mid]<=target){
                    st= mid+1;
                }else{
                    en = mid-1;
                }
            }
            idx=en;
            done=target-timereq[idx];
            ans.push_back(n-idx);
        }
        return ans;
    }
};