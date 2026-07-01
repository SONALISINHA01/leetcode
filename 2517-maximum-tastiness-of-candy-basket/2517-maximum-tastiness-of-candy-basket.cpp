class Solution {
public:
    bool valid(int mid,vector<int> &price, int k){
        int n = price.size();
        int temp=1;
        int exi = price[0];
        for(int i =1;i<n;i++){
            if(exi-price[i]>=mid){
                temp++;
                exi = price[i];
            }
            if(temp==k){
                return true;
            }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        int st  =0, en=0;
        sort(price.rbegin(),price.rend());
        en = price[0];
        int mid = (en-st)/2+st;
        int ans =0;
        while(st<=en){
            mid = (en-st)/2+st;
            if(valid(mid,price,k)){
                ans = mid;
                st=mid+1;
            }else{
                en = mid-1;
            }
        }
        return ans;
    }
};