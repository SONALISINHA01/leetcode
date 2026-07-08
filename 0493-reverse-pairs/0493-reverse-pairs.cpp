class SegmentTree{
    public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n,0);
    }
    void update(int pos, int index, int left, int right){
        if(left==right){
            tree[index]++;
            return;
        }
        int mid = (left+right)>>1;
        if(pos<=mid){
            update(pos,2*index+1,left,mid);
        }else{
            update(pos,2*index+2,mid+1,right);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int query(int ql, int qr, int index, int left, int right){
        //no overlap
        if(ql>right || qr<left){
            return 0;
        }
        // full overlap
        if(ql<=left && right<=qr){
            return tree[index];
        }
        //partial overlap
        int mid = (left+right)>>1;
        return query(ql,qr,2*index+1,left,mid)+query(ql,qr,2*index+2,mid+1,right);
    }
};
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int m = nums.size();
        vector<int> arr=nums;
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        SegmentTree* st = new SegmentTree(arr.size());
        int ans =0;
        for(int i=m-1;i>=0;i--){
            // find first idx where 2*arr[idx] >= nums[i]
            int lo = 0, hi = arr.size();
            while(lo < hi){
                int mid = (lo+hi)/2;
                if(2LL*arr[mid] < nums[i]) lo = mid+1;
                else hi = mid;
            }
            if(lo > 0){
                ans += st->query(0, lo-1, 0, 0, arr.size()-1);
            }
            int idx = lower_bound(arr.begin(),arr.end(),nums[i])-arr.begin();
            st->update(idx,0,0,arr.size()-1);
        }
        return ans;
    }
};