class Solution {
public:
    int dp[1501][1501][2];
    long long recc(int l,int r,vector<int>&requests,int side,long long time){
        //base case 
        if(l==0 && r==requests.size()-1){
            return 0;
        }
        if(dp[l][r][side]!=-1) return dp[l][r][side];
        long long ans=INT_MAX;
        // we have complete the interval l--r with time 
        //we will go to l-1
        int curr = side==0? requests[l] : requests[r];
        
        if(l>0){
            long long next=requests[l-1];
            long long newtime = time + abs(curr-next);

            long long cost = newtime + recc(l-1,r,requests,0,newtime);
            ans= min(ans,cost);
            
        }
        //then try go r+1
        if(r+1<requests.size()){
            long long next = requests[r+1];
            long long newtime = time+abs(curr-next);
            long long cost = newtime + recc(l,r+1,requests,1,newtime);
            ans= min(ans,cost);
            
        }
        return dp[l][r][side]=ans;
        
    }
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        //check if start is already there or not
        bool flag=false;
        for(const int& r:requests){
            if(r==start){
                flag=true;
                break;
            }
        }
        if(!flag){
            requests.push_back(start);
        }
        sort(requests.begin(),requests.end());
        
        int s= lower_bound(requests.begin(),requests.end(),start) - requests.begin();
        int side=0;
        long long time=0;
        
        memset(dp,-1,sizeof(dp));
        
        return recc(s,s,requests,side,time);
    }
};