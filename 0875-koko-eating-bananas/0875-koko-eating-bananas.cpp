class Solution {
public:
    bool koko(int &k , vector<int> piles, int h){
        int n = piles.size();
        int temp=0;
        for(int i =0;i<n ;i++){
            temp += piles[i]/k;
            if(piles[i]%k >0){
                temp++;
            }
            if(temp>h){
                return false;
            }
        }
        if(temp<=h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int en = 1e9, st =1;
        while(st<=en){
            int mid = st+(en-st)/2;
            if(koko(mid,piles,h)){
                en = mid-1;
            }else{
                st = mid+1;
            }
        }
        return st;
    }
};