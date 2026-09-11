class Solution {
public:
    set<string> ans;
    void helper(vector<int> &digits, vector<bool> &used,string temp){
        if(temp.size()==3){
            if(stoi(temp)%2==0){
                ans.insert(temp);
            }
            return;
        }
        for(int i=0;i<digits.size();i++){
            if(used[i]==true) continue;
            if(temp.size()==0 && digits[i]==0)continue;
            used[i]=true;
            helper(digits,used,temp+to_string(digits[i]));
            used[i]=false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        vector<bool> used(n,false);
        string temp = "";
        helper(digits,used,temp);
        return ans.size();
    }
};