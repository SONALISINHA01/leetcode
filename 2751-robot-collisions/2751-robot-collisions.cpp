class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n = positions.size();
        vector<pair<int,int>> realpo;
        for(int i =0;i<n;i++){
            realpo.push_back({positions[i],i});
        }
        sort(realpo.begin(),realpo.end());
        stack<int> st;
        for(int j =0;j<n;j++){
            int i = realpo[j].second;
            if(directions[i]=='R'){
                st.push(i);
            }else{
                while(!st.empty() && health[i]>0){
                    int k = st.top();
                    if(health[k]<health[i]){
                        st.pop();
                        health[i]--;
                        health[k]=0;
                    }else if(health[k]==health[i]){
                        st.pop();
                        health[i]=health[k]=0;
                    }else{
                        health[k]--;
                        health[i]=0;
                    }
                }
            }
        }
        vector<int> result;
        for(int i =0;i<n;i++){
            if(health[i]>0){
                result.push_back(health[i]);
            }
        }
        return result;
    }
};