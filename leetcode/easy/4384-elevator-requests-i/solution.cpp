class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int m=requests.size();
        int last=0;
        int ans=0;
        for(int i=0;i<m;i++){
            ans+=abs(requests[i]-last);
            last=requests[i];
        }
        return ans;
    }
};