class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1,false);
        prime[0]=true;
        prime[1]=true;
        for(int i =2;i*i<=n;i++){
            if(!prime[i]){
                for(int j =i*i;j<=n;j+=i){
                    prime[j]=true;
                }
            }
        }
        int count=0;
        for(int i =0;i<n;i++){
            if(!prime[i]) count++;
        }
        return count;
    }
};