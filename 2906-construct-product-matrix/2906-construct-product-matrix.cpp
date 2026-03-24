class Solution {
public:
    #define ll long long 
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll m = grid[0].size();
        ll sz = n*m;
        vector<ll> flat(sz);
        int k=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                flat[k]=grid[i][j];
                k++;
            }
        }
        vector<ll> preflat(sz,1),sufflat(sz,1);
        
        for(ll i =1;i<sz;i++){
            preflat[i]=(flat[i-1]*preflat[i-1])%12345;
        }
        for(ll i =sz-2;i>=0;i--){
            sufflat[i]=(flat[i+1]*sufflat[i+1])%12345;
        }
        vector<ll> an(sz);
        for(ll i=0;i<sz;i++){
            an[i]=(preflat[i]*sufflat[i])%12345;
        }
        ll l =0;
        vector<vector<int>> ans(n , vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=an[l]%12345;
                l++;
            }
        }
        return ans ;
    }
};