class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        //map to store last time it was done
        unordered_map<int,int>mpp;
        int n=tasks.size();
        long long time=1;
        for(int& t:tasks){
            if(!mpp.count(t)){
                mpp[t]=time;
                time++;
            }else{
                int last= mpp[t];
                // can be done in last+space+1 thus gap =space+1
                int gap=time-last;
                if(gap<space+1){
                    time+=(space+1-gap);
                }
                mpp[t]=time;
                time++;
            }
        }
        return time-1;
    }
};