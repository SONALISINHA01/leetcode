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
        vector<int> canbe;
        for(int i = left;i<=right;i++){
            if(prime[i]){
                canbe.push_back(i);
            }
        }
        if(canbe.size()<=1){
            return {-1,-1};
        }
        int mi= INT_MAX, x=-1,y=-1;
        for(int i=1;i<canbe.size();i++){
            if(mi>(canbe[i]-canbe[i-1])){
                mi = canbe[i]-canbe[i-1];
                x=canbe[i-1];
                y=canbe[i];
            }
        }
        return {x,y};
    }
};