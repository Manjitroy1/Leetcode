class Solution {
public:
    int cnt=0;
    bool sq(int val){
        int q= sqrt(val);
       return q*q==val;
    }
    // bool func(vector<int>&nums){
    //     int n=nums.size();
    //     for(int i=0;i<n-1;i++){
    //         if(!sq(nums[i]+nums[i+1])){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // int solve(vector<int>& nums) {
    //     int cnt=0;
    //     sort(nums.begin(),nums.end());
    //     do{
    //         if(func(nums)) cnt++;
    //     }while(next_permutation(nums.begin(),nums.end()));

    //     return cnt;
    // }
void recc(int curr, vector<int>& nums) {
    if(curr == nums.size()) {
        cnt++;
        return;
    }

    unordered_set<int> used;

    for(int i = curr; i < nums.size(); i++) {

        if(used.count(nums[i])) continue;
        used.insert(nums[i]);

        swap(nums[curr], nums[i]);

        if(curr == 0 || sq(nums[curr-1] + nums[curr]))
            recc(curr + 1, nums);

        swap(nums[curr], nums[i]);
    }
}

void help(int curr,vector<int> arr){
        if(curr>= arr.size()){
            cnt++;
            return ;
        }
        for(int i= curr;i<arr.size();i++){
            if(i== curr || arr[i]!= arr[curr]){
                swap(arr[curr],arr[i]);
                if(curr==0 || (curr>0 && sq(arr[curr-1]+arr[curr]))) help(curr+1,arr);
            }
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
    //    return solve(nums);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // recc(0,nums); 
        help(0,nums);
        return cnt;
    }
};