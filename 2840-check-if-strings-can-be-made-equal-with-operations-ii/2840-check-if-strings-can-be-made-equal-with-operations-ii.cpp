class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> even1,even2,odd1,odd2;
        for(int i=0;i<n;i+=2){
            even1.push_back(s1[i]);
            even2.push_back(s2[i]);
        }
        for(int i=1;i<n;i+=2){
            odd1.push_back(s1[i]);
            odd2.push_back(s2[i]);
        }
        sort(even1.begin(),even1.end());
        sort(even2.begin(),even2.end());
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());
        int ev = even1.size();
        int od = odd1.size();
        for(int i =0;i<ev;i++){
            if(even1[i]!=even2[i]){
                return false;
            }
        }
        for(int i =0;i<od;i++){
            if(odd1[i]!=odd2[i]){
                return false;
            }
        }
        return true;
    }
};