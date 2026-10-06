class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>store;
        int n=nums1.size();
        if(k==n){
            long long s=accumulate(nums1.begin(),nums1.end(),0LL);
            long long mn=*min_element(nums2.begin(),nums2.end());
            return mn*s;
        }
        for(int i=0;i<n;i++){
            store.push_back({nums2[i],nums1[i]});
        }
        sort(store.begin(),store.end()); //nums2 nums1
        //iterate through the back
        long long sum=0;
        // long long mn=store[n-1][0];
        long long ans=0;
        priority_queue<long long,vector<long long>,greater<long long>>pq; //min head
        
        int i=n-1;

        while(i>=0){
            sum+=store[i][1];
            pq.push(store[i][1]);

            while(pq.size()>k){
                sum-=(pq.top());
                pq.pop();
            }
            if(pq.size()==k){
                ans= max(ans,store[i][0]*sum);
            }
            i--;
        }
        return ans;
    }
};