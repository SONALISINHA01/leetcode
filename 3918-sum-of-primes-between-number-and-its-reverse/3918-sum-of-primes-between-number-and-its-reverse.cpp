class Solution {
public:
    bool computed = false;
    vector<bool> isprime=vector<bool>(1002,true);
    void sieve(){
        isprime[0]=false;
        isprime[1]=false;
        for(int i=2;i*i<=1000;i++){
            if(isprime[i]){
                for(int j=i*i;j<=1002;j+=i){
                    isprime[j]=false;
                }
            }
        }
    }
    int sumOfPrimesInRange(int n) {
        if(!computed){
            sieve();
            computed = true;
        }
        int r=0,temp =n;
        while(temp>0){
            r=r*10+(temp%10);
            temp/=10;
        }
        int mi = min(r,n);
        int ma = max(r,n);
        int ans=0;
        cout<<mi<<" "<<ma<<endl;
        for(int i=mi;i<=ma;i++){
            if(isprime[i]){

                ans+=i;
            }
        }
        return ans;
    }
};