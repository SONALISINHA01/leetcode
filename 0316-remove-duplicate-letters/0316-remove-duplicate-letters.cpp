class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        map<char,int> mp;
        map<char,bool> exist;
        for(int i =0;i<n;i++){
            mp[s[i]]=i;
        }
        stack<char> st;
        st.push(s[0]);
        exist[s[0]]=true;
        for(int i =1;i<n;i++){
            if(exist[s[i]]) continue;
            while(!st.empty() && st.top()>s[i] && mp[st.top()]>i ){
                exist[st.top()]=false;
                st.pop();
            }
            st.push(s[i]);
            exist[s[i]]=true;
        }
        string str;
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};