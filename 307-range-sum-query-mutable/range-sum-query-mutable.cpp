class NumArray {
public:
    int n;
    vector<int>bit;
    vector<int>nums;

    void upd(int idx,int val){
        while(idx<=n){
            bit[idx]+=val;
            idx+=(idx & -idx);
        }
    }
    int query(int idx){
        int ans=0;
        while(idx>0){
            ans+=bit[idx];
            idx-=(idx & -idx);
        }
        return ans;
    }
    NumArray(vector<int>& arr) {
        this->nums = arr;
        n=nums.size();
        bit.resize(n+1,0);

        for(int i=0;i<n;i++){
            upd(i+1,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff= val-nums[index];
        nums[index]=val;
        upd(index+1,diff);
        
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */