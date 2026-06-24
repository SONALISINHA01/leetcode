class Solution {
public:
    string largestMerge(string word1, string word2) {
        string merge ="";
        int i =0,j=0;
        int n = word1.size(),m =word2.size();
        while(i<n||j<m){
            if(i<n && j<m){
                if(word1[i]>word2[j]){
                    merge+=word1[i];
                    i++;
                }else if(word1[i]<word2[j]){
                    merge+=word2[j];
                    j++;
                }else{
                    string a = word1.substr(i);
                    string b = word2.substr(j);
                    if(a>b){
                        merge+=word1[i];
                        i++;
                    }else{
                        merge+=word2[j];
                        j++;
                    }
                }
            }else if(i<n){
                merge+=word1[i];
                i++;
            }else{
                merge+=word2[j];
                j++;
            }
        }
        return merge;
    }
};