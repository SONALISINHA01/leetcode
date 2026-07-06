class Solution {
public:
    int dx[8]={0,0,-1,1,1,-1,1,-1};
    int dy[8]={-1,1,0,0,1,1,-1,-1};
    map<int,int> freq;
    bool prime(int num){
        if(num<2){
            return false;
        }
        for(int i =2;i*i<=num;i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    void findallprime(vector<vector<int>> & mat, int i,int j,int num, int dir){
        int n = mat.size(), m = mat[0].size();
        int nx = i+dx[dir];
        int ny = j+dy[dir];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
            int temp = num;
            if(num > 100000000){
                return;
            }
            temp*=10;
            temp += mat[nx][ny];
            if(prime(temp) && temp>10){
                freq[temp]++;
            }
            findallprime(mat,nx,ny,temp,dir);
        }  
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                for(int dir=0;dir<8;dir++){
                    findallprime(mat,i,j,mat[i][j],dir);
                }
            }
        }
        int ma = INT_MIN;
        int ans =-1;
        for(auto [key,value]:freq){
            if(value>ma){
                ma = value;
                ans= key;
            }else if(ma ==value){
                ans = max(ans,key);
            }
        }
        return ans;
    }
};