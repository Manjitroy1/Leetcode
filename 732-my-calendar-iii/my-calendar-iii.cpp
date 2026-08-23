class MyCalendarThree {
public:
    map<int,int>mpp;
    int ans;
    MyCalendarThree() {
        ans=0;
    }
    
    int book(int startTime, int endTime) {
        mpp[startTime]++;
        mpp[endTime]--;
        int curr=0;
        for(auto& it:mpp){
            curr+=it.second;
            ans= max(ans,curr);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */