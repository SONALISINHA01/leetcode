class Solution {
public:
    void helper(vector<string> &ans,string temp, int& n, int op, int cl){
        if(cl==n){
            ans.push_back(temp);
            return;
        }
        if(op<n){
            helper(ans,temp+'(',n,op+1,cl);
        }
        if(cl<op){
            helper(ans,temp+')',n,op,cl+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int op=0,cl=0;
        string temp ="";
        helper(ans,temp,n,op,cl);
        return ans;

    }
};