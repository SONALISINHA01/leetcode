class Solution {
public:
    int numPrimeArrangements(int n) {
        int mod = 1000000007;
        vector<bool> prime(n+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i =2;i<=n;i++){
            if(prime[i]){
                for(int j =i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        int count=0;
        for(int i =1;i<=n;i++){
            if(prime[i]){
                count++;
            }
        }
        long long factp = 1;
        long long nonfactp =1;
        for(int i =1;i<=count;i++){
            factp = (factp*i)%mod;
        }
        for(int i =1;i<=(n-count);i++){
            nonfactp = (nonfactp*i)%mod;
        }
        return (factp*nonfactp)%mod;
    }
};