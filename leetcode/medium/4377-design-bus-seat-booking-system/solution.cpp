class BusBooking {
public:
    vector<vector<int>>bus;
    int cnt;
    int total;
    
    BusBooking(int n) {
        bus.resize(n+1,vector<int>(4,0));
        cnt=0;
        total=0;
    }
    
    void toggle(string seat) {
        //if it is on then turn it off
        //if it is off then onn
        //parse the string seat
        int c= seat[0]-'A';
        int row = stoi(seat.substr(1));

        int v= bus[row][c];
        
        if(v==0){
            cnt++;
            //we will take this seat
            // if(c==0){}
            
            if(c==1 || c==2){ //non window
                total++;
                bus[row][c]=1; //it cost 1;
            }else{//window seat we have to check adj
                
                if(c==0){
                    //we have to check c=1
                    if(bus[row][c+1]){
                        total+=3;
                        bus[row][c]=3; //this cost 3;
                    }else{
                        total++;
                        bus[row][c]=1;
                    }
                    
                }else{ //c==3
                    // we have to check c=2
                    if(bus[row][c-1]){
                        total+=3;
                        bus[row][c]=3; //this cost 3;
                    }else{
                        total++;
                        bus[row][c]=1;
                    }
                }
            }
        }else{
            cnt--;
            //we will release this seat
            total-=bus[row][c];
            bus[row][c]=0;
        }
        
    }
    
    int getTotalTime() {
        return total;
    }
    
    int getMinTime() {
        return cnt;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */