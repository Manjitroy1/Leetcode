class Solution {
public:

    bool check(int l, int& mid, vector<vector<int>>& nums) {

        mid = INT_MIN;

        for (const auto& vec : nums) {

            auto it = lower_bound(vec.begin(), vec.end(), l);

            if (it == vec.end()) {
                return false;
            }

            mid = max(mid, *it);
        }

        return true;
    }

    vector<int>better(vector<vector<int>>& nums) {

        int l = INT_MAX;
        int h = INT_MIN;

        for (const auto& vec : nums) {
            l = min(l, vec[0]);

            int n = vec.size();
            h = max(h, vec[n - 1]);
        }

        int a = l;
        int b = h;

        // Try every possible left endpoint
        for (l = l; l <= h; l++) {

            int mid;
            //the check funciton will mid update via check to auto adjust

            if (check(l, mid, nums)) {

                if (mid - l < b - a) {
                    a = l;
                    b = mid;
                }
                else if (mid - l == b - a) {

                    if (l < a) {
                        a = l;
                        b = mid;
                    }
                }
            }
        }

        return {a, b};
    }

    vector<int> smallestRange(vector<vector<int>>& nums) {
        // return better(nums); //tle
        using t=tuple<int,int,int>;  //value,ith vec, index of ith vec
        priority_queue<t,vector<t>,greater<t>>pq;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i][0]);
            pq.push({nums[i][0],i,0});
        }
        auto [x,idx,p]=pq.top();
        int a=x;
        int b=mx;

        while(true){
            auto [val,i,pos]= pq.top();
            pq.pop();

            if(mx-val < b-a){
                a=val;
                b=mx;
            }
            if(pos+1>= nums[i].size()) break;
            pq.push({nums[i][pos+1],i,pos+1});
            mx=max(mx,nums[i][pos+1]);
        }
        return {a,b};
    }
};