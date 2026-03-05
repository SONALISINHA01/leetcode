class Solution {
public:
    int sumOfMultiples(int n) {
        int ans=0;
        for(int i =3;i<=n;i++){
            int time=0;
            if(i%3==0){
                ans+=i;
                time++;
            }
            if(i%5==0&& time==0){
                ans+=i;
                time++;
            }
            if(i%7==0&& time==0){
                ans+=i;
            }
        }
        return ans;
    }
};