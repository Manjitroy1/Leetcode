class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq; //contains end time in ascending order

        int day=0;//starting day
        int cnt=0;
        int i=0;
        //we will try to complete with minimum  ending date from o to i
        //if ending is less than current day we can attend

        while(i<n || !pq.empty()){
            if(pq.empty()){
                day = max(0,events[i][0]);
            }
            //push the elements whose start is less than day
            while(i<n && events[i][0] <= day){
                pq.push(events[i][1]);
                i++;
            }
            // if ending is less than day we cannot attend those
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            while(!pq.empty()){
                pq.pop();
                cnt++;
                day++;
            }
        }
        return cnt;
    }
};