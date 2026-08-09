class SGTree{
public:
    vector<int>sgt;
    SGTree(int n){
        sgt.resize(4*n+1);
    }
    void build(int idx,int low,int high,vector<int>&arr){
        if(low==high){
            sgt[idx]=arr[low];
            return ;
        }
        int mid= (low+high)>>1;

        build(2*idx + 1, low,  mid,arr);
        build(2*idx + 2, mid+1,high,arr);
        sgt[idx] = sgt[2*idx + 1] + sgt[2*idx + 2];
    }
    int query(int idx,int low, int high, int l,int r){

        //no overlap. low high l r.  or l r low high
        if(l>high || r< low) return 0;

        //complete overlap. l low high  r
        if(l<=low && high <=r) return sgt[idx];

        //partial ovelap
        int mid= (low+high)>>1;
        int left= query(2*idx+1, low, mid,l,r);
        int right = query(2*idx+2, mid+1, high, l,r);
        return (left+right);
    }
    void update(int idx,int low, int  high, int pos,int val){
        if(low==high){
            sgt[idx] = val;
            return;
        }

        int mid= (low+high)>>1;

        if(pos<=mid) update(2*idx+1,low,mid, pos,val);
        else update(2*idx+2,mid+1,high,pos,val);

        sgt[idx] = sgt[2*idx+1] + sgt[2*idx + 2];
    }
};
class NumArray {
public:
    int n;
    SGTree sg;
    NumArray(vector<int>& nums) : n(nums.size()), sg(n) {
        sg.build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        sg.update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return sg.query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */