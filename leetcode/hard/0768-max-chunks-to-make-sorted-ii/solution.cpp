class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        if(nums==arr) return n;
        map<int,int>freq;
        // map<int,int>stt2;

        int cnt=0;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
            freq[nums[i]]--;

            if(freq[arr[i]]==0){
                freq.erase(arr[i]);
            }
            if(freq[nums[i]]==0){
                freq.erase(nums[i]);
            }
            if(freq.empty()){
                cnt++;
            }
        }
        return cnt;
    }
};