class MedianFinder {
public:
    priority_queue<int> pq1;
    priority_queue<int,vector<int> ,greater<int>> pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int sz1 = pq1.size();
        int sz2 = pq2.size();
        if(sz1 == 0 || num <= pq1.top()) {
            pq1.push(num);
        }
        else{
            pq2.push(num);
        }

        if(pq1.size() > pq2.size()+1) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        else if(pq2.size() > pq1.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
        int sz1 = pq1.size();
        int sz2 = pq2.size();
        int evod = sz1+sz2;
        double ans=0;
        if(evod%2==0){
            ans = (pq1.top()+pq2.top())/2.0;
            return ans;
        }
        if(sz1>sz2){
            ans = pq1.top();
            ans /=1.0;
            return ans;
        }
        ans =pq2.top();
        ans /=1.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */