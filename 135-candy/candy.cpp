class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>candy(n,0);

        using t=pair<int,int>;
        priority_queue<t,vector<t>,greater<t>>pq;

        for(int i=0;i<n;i++){
            pq.push({ratings[i],i});
        }

        while(!pq.empty()){
            auto node= pq.top();
            pq.pop();

            int v=node.first;
            int idx=node.second;


            int l = idx-1 >=0 ? ratings[idx-1]: 1e9;
            int r = idx+1 <n ? ratings[idx+1]: 1e9;

            int mnrating=min(l,r);

            int left = idx-1 >=0 ? candy[idx-1]:0;
            int right = idx+1 <n ? candy[idx+1]:0;

           //both small
           if(mnrating>=v) candy[idx] = 1;
           else if(l<v && r<v){
                candy[idx] =max(left,right)+1;
           }
           //both big or both equal
           //one small one equal  or one big one small rating
           else if(l<v){
            candy[idx] = left+1;
           }else{
            candy[idx]= right +1;
           }

        }
        return accumulate(candy.begin(),candy.end(),0);
        
    }
};