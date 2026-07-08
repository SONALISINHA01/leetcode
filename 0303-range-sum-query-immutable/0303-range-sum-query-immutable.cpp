class SegmentTree{
    public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n,0);
    }
    void build(int index,int left, int right,vector<int>& nums){
        if(left==right){
            tree[index]=nums[left];
            return;
        }
        int mid = (left+right)>>1;
        build(2*index+1,left,mid,nums);
        build(2*index+2,mid+1,right,nums);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int query(int ql,int qr,int index , int left, int right){
        //no overlapping
        if(ql> right || qr<left){
            return 0;
        }
        // full overlapping
        if(ql<= left &&  right<= qr){
            return tree[index];
        }
        // partial overlap
        int mid =(left+right)>>1;
        return query(ql,qr,2*index+1, left, mid)+query(ql,qr,2*index+2,mid+1,right);
    }
};
class NumArray {
public:
    SegmentTree* st;
    int n;
    NumArray(vector<int>& nums) {
       this->n= nums.size();
       st = new SegmentTree(n);
       st->build(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {
        return st->query(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */