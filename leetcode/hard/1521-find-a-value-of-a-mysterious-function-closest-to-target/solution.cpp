class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int n=arr.size();
        int ans=INT_MAX;
        unordered_set<int>stt;   // set will store all the & calculated values 
                                // set will contain at most 20 numbers every time becoz 20 bits
        for(int i=0;i<n;i++){
            unordered_set<int>temp;

            for(int v:stt){
                temp.insert(v & arr[i]);
            }
            temp.insert(arr[i]);

            for(int v:temp){
                ans=min(ans, abs(target-v));
            }
            stt=temp;
        }
        return ans;
        
    }
};