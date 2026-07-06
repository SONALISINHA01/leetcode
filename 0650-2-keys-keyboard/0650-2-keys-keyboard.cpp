class Solution {
public:
    int minSteps(int n) {
        vector<int> spf(1001);
        spf[0]=0;
        spf[1]=0;
        for(int i =2;i<=1000;i++){
            spf[i]=i;
        }
        for(int i =2;i<=1000;i++){
            if(spf[i]==i){
                for(int j =i*i;j<=1000;j+=i){
                    spf[j]=i;
                }
            }
        }
        int ans=0;
        while(n>1){
            ans+=spf[n];
            n=n/spf[n];
        }
        return ans;
    }
};