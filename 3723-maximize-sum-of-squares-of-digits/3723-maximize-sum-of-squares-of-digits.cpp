class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans="";
        int count=0;
        while(sum>0){
            if(count>num){
                return  "";
            }
            if(sum>=9){
                ans+=to_string(9);
                sum-=9;
            }else{
                ans+=to_string(sum);
                sum-=sum;
            }
            count++;
        }
        if(count>num){
            return  "";
        }
        while(count<num){
            ans+=to_string(0);
            count++;
        }
        return ans;
    }
};