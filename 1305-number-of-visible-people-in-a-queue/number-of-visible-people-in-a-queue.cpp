class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        //we can solve using stack 
        int n=heights.size();
        stack<int>stk;
        vector<int>ans(n,0);
        stk.push(heights[n-1]);
        
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!stk.empty() && stk.top() <= heights[i]){
                stk.pop();
                cnt++;
            }
            ans[i] = cnt + (!stk.empty());
            stk.push(heights[i]);
        }
        return ans;
    }
};