#define ll long long
class Solution {
public:
    const ll mod=1e9+7;
    ll powmod(ll a,ll p){
        ll res=1;
        while(p){
            if(p & 1){
                res=(res*a) % mod;
            }
            a= (a*a) % mod;
            p>>=1;
        }
        return res;
    }
    ll comb(int n,int r){
        r=min(r,n-r);
        ll ways=1;

        for(int i=0;i<r;i++){
            ways = (ways* (n-i)) % mod;
            ways = (ways* powmod(i+1,mod-2)) % mod;
        }
        return ways;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        int n=s.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        if(freq.size()<k || k > 26) return 0;
        // if(freq.size()==k) return 1;
        vector<int>nums;
        for(auto& node:freq){
            nums.push_back(node.second);
        }

        sort(nums.rbegin(),nums.rend()); //sort in desc
        //we have to find sum of last k element 
        //that is the maximum among all k-subsequences that equal to target
        // we have to find total possible k element sum == target
        //total possibility is the product of that k window
        int m=nums.size();

        int x=nums[k-1];
        //number of number greater than x;
        int greater=0;
        ll ans=1;

        for(int elem:nums){
            if(elem>x){
                ans= (ans * 1LL*elem)%mod;
                greater++;
            }
        }

        int need = k-greater;

        //eqal to x
        int equal=0;
        for(int elem:nums){
            if(elem==x){
                equal++;
            }
        }

        // number of combination of x::  comb(equal,need)
        ll ways=1;
        ways=comb(equal,need);
        ans= (ans*ways)%mod;

        for(int i=0;i<need;i++){
            ans=(ans*x)%mod;
        }
        return ans;
    }
};