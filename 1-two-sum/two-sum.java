class Solution {
    public int[] twoSum(int[] nums, int target) {
        //iterate over each element
        //check if the need is in the map or not
        //then insert the num in the mpp

        //unorderemap
        HashMap<Integer,Integer>mpp= new HashMap<>();
        // ArrayList<Integer>ans = new ArrayList<>();
        int[] ans = {-1,-1};

        for(int i=0;i<nums.length;i++){
            int need =target-nums[i];
            if(mpp.containsKey(need)){
                ans[0]=i;
                ans[1]= mpp.get(need);
                return ans;
            }
            mpp.put(nums[i],i);
        }
        return ans;
    }
}