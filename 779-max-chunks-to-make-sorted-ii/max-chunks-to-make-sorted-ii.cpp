class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<int>nums=arr;
        sort(nums.begin(),nums.end());
        if(nums==arr) return n;
        map<int,int>stt1;
        map<int,int>stt2;

        int cnt=0;
        for(int i=0;i<n;i++){
            stt1[arr[i]]++;
            stt2[nums[i]]++;

            if(stt1==stt2){
                cnt++;
                stt1.clear();
                stt2.clear();
            }
        }
        return cnt;
    }
};