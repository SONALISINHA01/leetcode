class Solution {
public:
    int addDigits(int num) {
        string temp=to_string(num);
        while(temp.size()>1){
            int sum =0;
            for(int i=0;i<temp.size();i++){
                sum += temp[i]-'0';
            }
            temp =to_string(sum);
        }
        return stoi(temp);
    }
};