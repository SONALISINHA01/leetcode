class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right+1, true);
        prime[0]=false;
        prime[1]=false;
        for(int i =2;i<=right;i++){
            if(prime[i]){
                for(long long j =(long long)i*i;j<=right;j+=i){
                    prime[j]=false;
                }
            }
        }
        int cur=-1,prev=-1;
        int m=INT_MAX;
        int anx=-1,any=-1;
        for(int i = left;i<=right;i++){
            if(prime[i]){
                if(cur!=-1){
                    prev=cur;
                    cur=i;
                    if(m>(cur-prev)){
                        m = cur-prev;
                        anx=prev;
                        any=cur;
                    }
                }
                cur=i;

            }
        }
        if(prev==-1){
            return {-1,-1};
        }
        return {anx,any};
    }
};