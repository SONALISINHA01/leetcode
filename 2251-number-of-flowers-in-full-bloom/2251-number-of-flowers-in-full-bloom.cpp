class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        vector<int> start,ends;
        for(int i =0;i<n;i++){
            start.push_back(flowers[i][0]);
            ends.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(ends.begin(),ends.end());
        vector<int> blooming;
        for(int i=0;i<people.size();i++){
            int bloomed = upper_bound(start.begin(),start.end(),people[i])-start.begin();
            int withered = lower_bound(ends.begin(),ends.end(),people[i])-ends.begin();
            blooming.push_back(bloomed-withered);
        }
        return blooming;
    }
};