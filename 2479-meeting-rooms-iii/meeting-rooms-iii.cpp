#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //i have unique start time
        //number of rooms is less than 100

        //for this meething find the lowest room number that is avail
        sort(meetings.begin(),meetings.end());
        //first apply the brute force
        vector<vector<ll>>room(n,vector<ll>(2,0)); // end time , cnt
        int m= meetings.size();
        ll ans=0;

        for(int i=0;i<m;i++){
            //all are full then find the min endone
            ll mn=room[0][0]; //end time of the first room
            int idx=0;
            bool done=true;

            for(int j=0;j<n;j++){
                if(mn > room[j][0]){
                    idx=j;
                    mn=room[j][0];
                }
                //i got endtime less than curr start put this
                if(room[j][0]<=meetings[i][0]){
                    //i will take this room
                    room[j][0] = meetings[i][1];
                    room[j][1]++;
                    ans=max(ans,room[j][1]);
                    done=false;
                    break;
                }

            }
            if(done){//i have to give room for this meeting 
                //assign the that is ending soon \\ i have idx
                room[idx][0] = mn + (meetings[i][1] - meetings[i][0]);
                room[idx][1]++;
                ans=max(ans,room[idx][1]);
            }
        }
        for(int i=0;i<n;i++){
            // cout<<room[i][0]<<" "<<room[i][1]<<endl;

            if(room[i][1]==ans){
                return i;
            }
        }
        return 0;
    }
};