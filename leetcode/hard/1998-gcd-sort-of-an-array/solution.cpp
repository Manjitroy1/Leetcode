class Solution {
public:
    vector<int>parent;
    vector<int>size;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int u,int v){
        int up=find(u);
        int vp=find(v);
        if(up==vp) return;
        if(size[up] < size[vp]) swap(up,vp);

        size[up]+=size[vp];
        parent[vp]=up;
        return;
    }
    bool gcdSort(vector<int>& nums) {
        vector<int>nums2(nums);
        sort(nums2.begin(),nums2.end());

        int n=nums.size();
        int mx=nums2[n-1];

        parent.resize(mx+1,0);
        size.resize(mx+1,1);

        for(int i=1;i<=mx;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=2;j<=sqrt(nums[i]);j++){
                if(nums[i]%j==0){
                    unite(nums[i],j);
                    unite(nums[i], nums[i]/j);
                }
            }
        }

        for(int i=0;i<n;i++){
            if( find(nums[i]) != find(nums2[i]) ) return false;
        }
        return true;
    }
};