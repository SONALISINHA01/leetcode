class SegmentTree{
    public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n,0);
    }
    void build(int index,int left, int right, vector<int>& nums){
        if(left==right){
            tree[index]=nums[left];
            return;
        }
        int mid = (left+right)>>1;
        build(2*index+1,left,mid,nums);
        build(2*index+2,mid+1,right,nums);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    void update(int i, int val, int index,int left,int right){
        if(left == right){
            tree[index]=val;
            return;
        }
        int mid =(left+right)>>1;
        if(i<=mid){
            update(i,val,2*index+1,left,mid);
        }else{
            update(i,val,2*index+2,mid+1,right);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int  query(int ql,int qr,int index, int left,int right){
        // no overlap
        if(right<ql || left>qr){
            return 0;
        }
        // full overlap
        if(right<=qr && left>=ql){
            return tree[index];
        }
        //partial overlap
        int mid = (right+left)>>1;
        return query(ql,qr,2*index+1,left,mid)+query(ql,qr,2*index+2,mid+1, right);
    }
};
class NumArray {
public:
    SegmentTree* st;
    int n;
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        st = new SegmentTree(n);
        st->build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        st->update(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return st->query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */