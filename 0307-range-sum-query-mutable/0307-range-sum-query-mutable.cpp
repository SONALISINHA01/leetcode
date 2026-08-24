class SegmentTree{
    public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n,0);
    }
    void build(int index, int left,int right, vector<int> &nums){
        if(left==right){
            tree[index]=nums[left];
            return;
        }
        int mid =(left+right)>>1;
        build(2*index+1,left,mid,nums);
        build(2*index+2,mid+1,right,nums);
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    void update(int index, int pos, int val, int left, int right){
        if(right==left){
            tree[index]= val;
            return;
        }
        int mid = (left+right)>>1;
        if(pos<=mid){
            update(2*index+1,pos,val,left,mid);
        }else{
            update(2*index+2,pos,val,mid+1,right);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
    }
    int sumrange(int index,int ql, int qr,int left,int right){
        if(ql>right || qr<left){
            return 0;
        }
        if(ql<=left && right<=qr){
            return tree[index];
        }
        int mid = (left+right)>>1;
        return sumrange(2*index+1, ql,qr,left,mid)+sumrange(2*index+2,ql,qr, mid+1,right);
    }
};
class NumArray {
public:
    SegmentTree* st;
    int n;
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        st=new SegmentTree(n);
        st->build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        st->update(0,index,val,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return st->sumrange(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */