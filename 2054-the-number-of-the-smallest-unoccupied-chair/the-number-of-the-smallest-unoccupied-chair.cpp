class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
        int n=times.size();
        unordered_map<int,int>mpp;  ///arrival and index

        for(int i=0;i<n;i++){
            mpp[times[i][0]]=i;
        }
        sort(times.begin(),times.end());

        if(target==mpp[times[0][0]]) return 0;

        using t= pair<int,int>;
        priority_queue<t,vector<t>,greater<t>>pq;
       
        priority_queue<int,vector<int>,greater<int>>kursi;  //to get the smallest chair

        pq.push({times[0][1],0}); //push the first arrived one with chair num 0

        int chair=0;

        for(int i=1;i<n;i++){
            int arr=times[i][0];
            int dept=times[i][1];
            int idx= mpp[arr];

            // if(!pq.empty()){//vacant all the chairs that are possibly to leave
            //     auto [leav,chr] =pq.top();

            while(!pq.empty() && pq.top().first <= arr){
                kursi.push(pq.top().second);
                pq.pop();
            }
            // }
            //we have to give him chair
            //chair availibel
            if(!kursi.empty()){
                if(target==idx) return kursi.top();
                pq.push({dept,kursi.top()}); //give the min chair
                kursi.pop();
            }
            //chair not availbele
            else{
                chair++; //new chair
                if(target==idx) return chair;
                pq.push({dept,chair});
            }
        }
        return -1;
    }
};