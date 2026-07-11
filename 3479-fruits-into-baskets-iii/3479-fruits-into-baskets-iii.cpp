class SegmentTree{
    public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n,0);
    }
    void build(int left,int right,int index,vector<int> &basket){
        if(left==right){
            tree[index]=basket[left];
            return;//forgot
        }
        int mid = (left+right)>>1;
        build(left,mid,2*index+1,basket);
        build(mid+1,right,2*index+2,basket);
        tree[index]=max(tree[2*index+1],tree[2*index+2]);
    }
    void update(int pos,int index,int val,int left,int right){
        if(left==right){
            tree[index]=val;//wrongly used pos instead of index
            return;
        }
        int mid = (left+right)>>1;
        if(pos>mid){
            update(pos,2*index+2,val,mid+1,right);//wrong indexing of index
        }else{
            update(pos,2*index+1,val,left,mid);//wrong indexing of index
        }
        tree[index]=max(tree[2*index+1],tree[2*index+2]);
    }
    bool query(int val,int index,int left,int right,int m){
        if(tree[index]<val){
            return false;
        }
        if(left==right && tree[index]>=val){
            update(left,0,-1,0,m-1);
            return true;
        }
        int mid=(left+right)>>1;
        if(tree[2*index+1]>=val){//shouldn't compare with right should compare with val
            return query(val,2*index+1,left,mid,m);
        }else{
            return query(val,2*index+2,mid+1,right,m);
        }
        return false;
    }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int m = baskets.size();
        SegmentTree st(m);
        st.build(0,m-1,0,baskets);
        int n= fruits.size();
        int ans =0;
        for(int i =0;i<n;i++){
            if(!st.query(fruits[i],0,0,m-1,m)){//st.query not query
                ans++;
            }
        }
        return ans;
    }
};