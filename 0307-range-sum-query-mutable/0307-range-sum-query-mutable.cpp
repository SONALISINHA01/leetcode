class SegmentTree{
    public:
    vector<int> tree;//tree that we are gonna work on - our deary lil segment tree
    SegmentTree(int n){
        tree.resize(4*n,0);//giving it size and initial value
    }
    // we are going to build the initial tree on which all the queries will be done on.
    //              0           0       n-1            nums
    void build(int index, int left,int right, vector<int> &nums){
        // index is used for tree
        if(left==right){//we have reached the leaf node, we will assign it value from nums array
            tree[index]=nums[left];// left==right, are same so it doesnt matter, which we use
            return;
        }
        int mid = (left+right)>>1;//the right shift operator divides it by 2 dumbass!!
        build(2*index+1,left,mid,nums);
        build(2*index+2,mid+1,right,nums);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    void update(int i,int index,int left,int right,int val){
        if(left==right){
            tree[index]=val;
            return;
        }
        int mid=(left+right)>>1;
        if(i<=mid){
            update(i,2*index+1,left,mid,val);
        }else{
            update(i,2*index+2,mid+1,right,val);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int query(int ql,int qr,int index, int left, int right){
        // no overlap
        if(right<ql || left>qr){
            return 0;
        }
        // full overlap
        if(left>=ql && right<=qr){
            return tree[index];
        }
        // partial overlap
        int mid = (left+right)>>1;
        return query(ql,qr,2*index+1,left,mid)+query(ql,qr,2*index+2,mid+1,right);
    }
};
class NumArray {
public:
    SegmentTree* st;
    int n;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->n=n;
        st= new SegmentTree(n);
        st->build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        st->update(index,0,0,n-1,val);
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