class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i =0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }else{
                int rock = asteroids[i];
                while(!st.empty()&&st.top()>0 &&rock!=0){
                    if(st.top()>abs(rock)){
                        rock=0;
                    }else if(st.top()==abs(rock)){
                        st.pop();
                        rock=0;
                    }else{
                        st.pop();
                    }
                }
                if(rock!=0){
                    st.push(rock);
                }
            }
        }
        vector<int> ans(st.size());
        for(int i = st.size() - 1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};