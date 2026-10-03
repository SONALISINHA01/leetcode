class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> idxs;
        stack<char> st;
        int n = s.size();
        idxs.push(-1);
        int ans = 0;
        int i =0;
        while(i<n){
            if(s[i]=='('){
                st.push('(');
                idxs.push(i);
            }else{
                if(!st.empty()){
                    st.pop();
                    idxs.pop();
                    ans = max(ans,i-idxs.top());
                }
                else{
                    idxs.push(i);
                }
            }
            i++;
        }
        return ans ;
    }
};
