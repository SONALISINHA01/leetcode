class Solution {
public:
    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        int n = rc.size();
        vector<long long> prefixsum(n,0);
        prefixsum[0]=rc[0];
        for(int i=1;i<n;i++){
            prefixsum[i]=prefixsum[i-1]+rc[i];
        }
        int i=0,j=0;
        int ans=0;
        deque<int> q;
        while(i<n){
            while(!q.empty()&&q.back()<ct[i]){
                q.pop_back();
            }
            q.push_back(ct[i]);
            long long expense = (q.front());
            if(j>0){
                expense +=(1LL)* (i-j+1)*(prefixsum[i]-prefixsum[j-1]);
            }else{
                expense+=(1LL)*(i-j+1)*(prefixsum[i]);
            }

            while(j<=i && expense>budget){
                if(q.front() == ct[j]){
                    q.pop_front();
                }
                j++;
                expense = q.empty() ? 0 : q.front();
                if(j>0){
                    expense +=(1LL)* (i-j+1)*(prefixsum[i]-prefixsum[j-1]);
                }else{
                    expense+=(1LL)*(i-j+1)*(prefixsum[i]);
                }
            }
            ans = max(ans,(i-j+1));
            i++;
        }
        return ans;
    }
};