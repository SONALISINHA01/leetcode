class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        int n = routes.size();
        if(source == target){
            return 0;
        }
        unordered_map<int, vector<int>> mp;
        
        for(int route=0;route<n;route++){
            int m = routes[route].size();
            for(int stops =0;stops<m;stops++){
                // mp[stops].push_back(route);
                mp[routes[route][stops]].push_back(route);

            }
        }
        queue<int> q;
        set<int> seen;
        for(auto root:mp[source]){
            q.push(root);
            seen.insert(root);
        }
        int train =1;
        while(q.size()>0){
            int lvlsz = q.size();
            while(lvlsz-->0){
                int route = q.front();
                q.pop();
                for(auto stop: routes[route]){
                    if(stop == target){
                        return train;
                    }
                    for(auto nextroute:mp[stop]){
                        if(seen.find(nextroute)==seen.end()){
                            seen.insert(nextroute);
                            q.push(nextroute);
                        }
                    }
                }
            }
            train++;
        }
        return -1;
    }
};