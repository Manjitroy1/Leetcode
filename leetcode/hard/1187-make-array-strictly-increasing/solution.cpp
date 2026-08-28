class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end()); //unique element
        int n=arr1.size();
        int m=arr2.size();
        //we have two choices
        //keep the same number or replace with the upperbound with cost 1

        // dp[last]= minimum operation 
        map<int,int>dp; //prev element with mininum cost till that index

        dp[arr1[0]]=0; //keep the same;
        

        if(!arr2.empty()){
            //minimum value 
            if(arr2[0]<arr1[0]) dp[arr2[0]]=1;
            // dp[arr2[0]]=1; //replace with the first elem of arr2
        }
       

        for(int i=1;i<n;i++){ //try for all possible index
            map<int,int>newdp; ///we will create newdp with help of prevone

            for(const auto&[last,cost]:dp){
                //we will not replace
                if(arr1[i]>last){
                    if(!newdp.count(arr1[i])){
                        newdp[arr1[i]]=cost;
                    }
                    else{
                        newdp[arr1[i]] = min(newdp[arr1[i]],cost);
                    }
                }
                //we will replace with upperbound
                auto it=upper_bound(arr2.begin(),arr2.end(),last);
                if(it!=arr2.end()){//there is an upperbound val
                    int val=*it;
                    if(!newdp.count(val)){
                        newdp[val]=cost+1;
                    }else{
                        newdp[val]=min(newdp[val],cost+1);
                    }
                }

            }
            dp=newdp;
        }
        int ans=INT_MAX;
        for(const auto& [last,cost]:dp){
            ans=min(ans,cost);
        }  

        return ans>=INT_MAX? -1:ans;
    }
};