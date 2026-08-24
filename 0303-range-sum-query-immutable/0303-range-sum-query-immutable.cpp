class SegmentTree{
    public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n,0);
    }
    void build(int index, int left, int right, vector<int> &nums){
        if(left==right){
            tree[index]=nums[left];
            return;
        }
        int mid=(left+right)>>1;
        build(2*index+1,left,mid,nums);
        build(2*index+2,mid+1,right,nums);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int query(int index,int ql,int qr,int left, int right){
        if(ql>right || qr<left){
            return 0;
        }
        if(ql<=left && qr>=right){
            return tree[index];
        }
        //partial overlap
        int mid = (left+right)>>1;
        return query(2*index+1,ql,qr,left,mid)+query(2*index+2,ql,qr,mid+1,right);
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
    
    int sumRange(int left, int right) {
        return st->query(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */