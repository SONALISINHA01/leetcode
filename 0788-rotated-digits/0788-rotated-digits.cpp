class Solution {
public:
    int rotatedDigits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int temp = i;
            int com = 0;
            int mul = 1;
            bool invalid = false;
            int zeroend=1;
            while(temp%10==0){
                zeroend*=10;
                temp/=10;
            }
            while (temp >0) {
                int a = temp % 10;
                temp /= 10;
                if (a == 0 || a == 1 || a == 8) {
                    com += mul * a;
                } else if (a == 2) {
                    com += mul * 5;
                } else if (a == 5) {
                    com += mul * 2;
                } else if (a == 6) {
                    com += mul * 9;
                } else if (a == 9) {
                    com += mul * 6;
                } else {
                    dp[i] = dp[i - 1];
                    invalid = true;
                    break;
                }
                mul*=10;
            }
            // cout<<"com"<<com<<" ";
            // cout<<"i "<<i<<endl;
            if (invalid) {
                continue;
            } else {
                //cout << "com" << com << " ";
                //cout << "i " << i << endl;
                if(zeroend>0){
                    com*=zeroend;
                }
                if (com != i) {
                    //cout<< com <<" "<<i<<endl;
                    dp[i] = dp[i - 1] + 1;
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
        return dp[n];
    }
};