class SegmentTree{
    public:
    vector<int> tree;
    SegmentTree(int n){
        tree.resize(4*n,0);
    }
    void update(int pos,int index,int left, int right){
        if(left==right){
            tree[index]++;
            return;
        }
        int mid = (left+right)>>1;
        if(pos>mid){
            update(pos,2*index+2,mid+1,right);
        }
        if(pos<=mid){
            update(pos,2*index+1,left,mid);
        }
        tree[index]= tree[2*index+1]+tree[2*index+2];
    }
    int query(int ql,int qr,int index, int left, int right){
        //no overlap
        if(ql>right|| qr<left){
            return 0;
        }
        //full overlapping
        if(left>=ql && qr>=right){
            return tree[index];
        }
        //partial overlapping
        int mid = (left+right)>>1;
        return query(ql,qr,2*index+1,left,mid)+query(ql,qr,2*index+2,mid+1,right);
    }
    
};
class Solution {
public:
    int binsearch(vector<int>& arr,int val){
        int left = 0,right = arr.size()-1;
        int mid;
        while(left<=right){
            mid = (right-left)/2 + left;
            if(arr[mid]==val){
                return mid;
            }else if(arr[mid]<val){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return -1;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        SegmentTree st(arr.size());
        vector<int> ans(nums.size(),0);
        for(int i = nums.size()-1;i>=0;i--){
            int sortedidx = binsearch(arr,nums[i]);
            ans[i]=st.query(0,sortedidx-1,0,0,arr.size()-1);
            st.update(sortedidx,0,0,arr.size()-1);
        }
        return ans;
    }
};