#define ll long long
class Solution {
public:
    long long better(vector<int>& nums) {
        int n=nums.size();
        ll ans=0;
        int l=0;
        multiset<int>stt;
        for(int r=0;r<n;r++){
            stt.insert(nums[r]);
            int mn= *stt.begin();
            int mx = *prev(stt.end());

            while(l<r && !stt.empty() && (mx-mn)>2){
                auto it = stt.find(nums[l]);
                stt.erase(it);
                l++;
                mn= *stt.begin();
                mx = *prev(stt.end());
            }
            ans += (r-l+1)*1LL;        
        }
        return ans;
    }
    long long best(vector<int>& nums) {
        int n=nums.size();
        //using mono tonic dequeue
        deque<int>mn;
        deque<int>mx;
        long long ans =0;

        int l=0;
        for(int r=0;r<n;r++){

            int x =nums[r];

            //pusing the element
            while(!mn.empty() && nums[mn.back()] > x){
                mn.pop_back();
            }
            mn.push_back(r);

            while(!mx.empty() && nums[mx.back()] < x){
                mx.pop_back();
            }
            mx.push_back(r);

            //remove outdated elemnt
            while(!mn.empty() && mn.front() < l){
                mn.pop_front();
            }
            while(!mx.empty() && mx.front() < l){
                mx.pop_front();
            }

            while(l<r && nums[mx.front()] - nums[mn.front()] > 2){
                if(mx.front()==l) mx.pop_front();
                if(mn.front()==l) mn.pop_front();
                l++;
            }
            ans+=(r-l+1);
        }
        return ans;
    }
    long long continuousSubarrays(vector<int>& nums) {
        return best(nums);
    }
};