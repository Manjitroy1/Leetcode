class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n=tasks.size();
        int m=shifts.size();

        //presum of tasks
        vector<long long>pre(n,0);
        pre[0]=tasks[0];
        for(int i=1;i<n;i++){
            pre[i]=1LL*tasks[i] + pre[i-1];
        }
        //pre is already in sorted can use binary search
        vector<int>ans(m,0);

        long long sum=0;
        for(int i=0;i<m;i++){
            sum+=shifts[i];
            int up= upper_bound(pre.begin(),pre.end(),sum)- pre.begin();
            int left = n-up;
            if(left==0) sum=0;
            
            ans[i]=left;
        }
        return ans;
        
    }
};