class LockingTree {
public:
    vector<int> parent;
    vector<int> status;
    vector<vector<int>> adj;
    int n;
    LockingTree(vector<int>& parent) {
        this->parent = parent;
        n = parent.size();
        status.resize(parent.size(),-1);
        adj.resize(parent.size());
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(status[num]==-1){
            status[num]=user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(status[num]==user){
            status[num]=-1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if(status[num]!= -1)return false;
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(num);
        visited[num]=true;
        vector<int> locked;
        while(q.size()>0){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();q.pop();
                for(int i =0;i<adj[curr].size();i++){
                    if(visited[adj[curr][i]]==false){
                        if(status[adj[curr][i]]!=-1){
                            locked.push_back(adj[curr][i]);
                        }
                        visited[adj[curr][i]]=true;
                        q.push(adj[curr][i]);
                    }
                }
            }
        }
        if(locked.size()<1)return false;
        int curr = parent[num];
        while (curr != -1) {
            if (status[curr] != -1) return false;
            curr = parent[curr];
        }
        for(int i =0;i<locked.size();i++){
            status[locked[i]]=-1;
        }
        status[num]=user;
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */