class Solution {
public:
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();
        
        int block=sqrt(n);

        vector<bool>ans(q,false);

        for(int i=0;i<q;i++){
            queries[i].push_back(i); //store the index
        }

        sort(queries.begin(),queries.end(),[&](auto& a,auto& b){
            int ba=a[0]/block;
            int bb=b[0]/block;
            
            if(ba!=bb) return ba<bb; //re order the queries on the basis least block size at begin
            return a[1]<b[1];        // biggest r at last
        });

        unordered_map<int,int>freq;  //num freq
        int oddfreq=0;
        int currl=0;
        int currr=-1;

        for(int i=0;i<q;i++){
            
            int l=queries[i][0];
            int r=queries[i][1];
            int idx=queries[i][2];

            while(currl>l){ //l move to left
                currl--;
                freq[nums[currl]]++;
                if(freq[nums[currl]]%2==1) oddfreq++;
                else oddfreq--;
            }
            while(currr<r){ //r move to right
                currr++;
                freq[nums[currr]]++;
                if(freq[nums[currr]]%2==1) oddfreq++;
                else oddfreq--;
                
            }
            while(currl<l){
                if(freq[nums[currl]]%2==1) oddfreq--;
                else oddfreq++;
                
                freq[nums[currl]]--;
                if(freq[nums[currl]]==0) freq.erase(nums[currl]);
                currl++;
            }
            while(currr>r){
                if(freq[nums[currr]]%2==1) oddfreq--;
                else oddfreq++;
                
                freq[nums[currr]]--;
                if(freq[nums[currr]]==0) freq.erase(nums[currr]);
                
                currr--;
            }

            if(freq.size()==k && oddfreq==0) ans[idx]=true;
        }
        return ans;
    }
};