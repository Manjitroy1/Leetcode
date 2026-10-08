class Solution {
public:
    const int total = 1e5+1;
    vector<int>bit;
    const int mod= 1e9+7;

    void update(int idx,int val){
        while(idx<=total){
            bit[idx]+=val;
            idx+=(idx & -idx);
        }
    }
    int query(int idx){ //sum till this index
        int ans=0;
        while(idx>0){
            ans+=bit[idx];
            idx-=(idx & -idx);
        }
        return ans;
    }
    int createSortedArray(vector<int>& instructions) {
        //total number of number less than this 
        // toal number of number greater than this
        int n=instructions.size();

        bit.resize(total,0);

        int cost=0;
        for(int i=0;i<n;i++){
            int val=instructions[i];
            //update
            //query
            int smal = query(val-1);
            int big= i - query(val); 

            update(val,1);
            cost= (cost + min(smal,big)) % mod;
        }

        //apply fenwick tree
        return cost;

        
    }
};