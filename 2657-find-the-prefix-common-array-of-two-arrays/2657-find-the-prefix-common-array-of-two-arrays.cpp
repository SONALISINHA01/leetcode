class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> found(n,0);
        map<int,int> mpa,mpb;
        mpa[a[0]]++;
        mpb[b[0]]++;

        if(a[0]==b[0]){
            found[0]=1;
        }
        for(int i =1;i<n;i++){
             found[i]=found[i-1];
            if(a[i]==b[i]){
                found[i]++;
                // mpa[a[i]]++;
                // mpb[b[i]]++;
            }else{
                if(mpa.find(b[i])!=mpa.end()){
                    found[i]++;
                    // mpa[a[i]]++;
                    // mpb[b[i]]++;
                }
                if(mpb.find(a[i])!=mpb.end()){
                    found[i]++;
                    // mpa[a[i]]++;
                    // mpb[b[i]]++;
                }
            }
            mpa[a[i]]++;
            mpb[b[i]]++;
        }
        return found;
    }
};