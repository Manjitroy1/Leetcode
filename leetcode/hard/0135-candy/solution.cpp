class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        // vector<int>candy(n,0);
        vector<int>candy(n,1);


        using t=pair<int,int>;
        priority_queue<t,vector<t>,greater<t>>pq;

        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }

        while(!pq.empty()){

            auto [v, idx] = pq.top();
            pq.pop();

            if (idx > 0 && ratings[idx - 1] < v) {
                candy[idx] = max(candy[idx], candy[idx - 1] + 1);
            }

            if (idx + 1 < n && ratings[idx + 1] < v) {
                candy[idx] = max(candy[idx], candy[idx + 1] + 1);
            }

        //     int l = idx-1 >=0 ? ratings[idx-1]: 1e9;
        //     int r = idx+1 <n ? ratings[idx+1]: 1e9;

        //     int mnrating=min(l,r);

        //     int left = idx-1 >=0 ? candy[idx-1]:0;
        //     int right = idx+1 <n ? candy[idx+1]:0;

        //    //both  big or equal
        //    if(mnrating>=v) candy[idx] = 1;
        //    //both small
        //    else if(l<v && r<v){
        //         candy[idx] =max(left,right)+1;
        //    }
        //    //one small one equal  or one big one small rating
        //    else if(l<v){
        //     candy[idx] = left+1;
        //    }else{
        //     candy[idx]= right +1;
        //    }

        }
        return accumulate(candy.begin(),candy.end(),0);
        
    }
};