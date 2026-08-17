class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m=requests.size();
        int total=1<<m;
        vector<vector<long long>>dp(total,vector<long long>(m,LLONG_MAX));

        // int dummymask=0;
        
        for(int i=0;i<m;i++){
            long long arrive= 1LL* requests[i][0];
            int floor= requests[i][1];
            // dummymask |= (1<<floor);

            long long time = abs(start-floor);
            time = max(time,arrive);
            dp[1<<i][i]= time;
        }

        for(int mask=1;mask<total;mask++){
            for(int last=0;last<m;last++){
                if( !(mask & 1<<last)) continue;
                if(dp[mask][last]>=LLONG_MAX) continue;
                
                long long currtime= dp[mask][last];
                int currfloor = requests[last][1];

                for(int j=0;j<m;j++){
                    if(mask & (1<<j)) continue;
                    int nxtfloor=requests[j][1];
                    long long arrival= 1LL*requests[j][0];
                    
                    long long newtime = currtime + abs(nxtfloor-currfloor);
                    int newmask = mask | (1<<j);
                    newtime = max(newtime, arrival);
                    dp[newmask][j] = min(newtime,dp[newmask][j]);
                }
            }
        }
        int full= (1<<m) -1;
        
        long long ans = LLONG_MAX;
        for(int i=0;i<m;i++){
            ans = min(ans,dp[full][i]);
        }
        return ans;
    }
};