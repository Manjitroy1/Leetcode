class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp); 
        int n=courses.size();

        priority_queue<int>pq;
        int timetaken=0;

        for(int i=0;i<n;i++){
            if(courses[i][0]>courses[i][1]) continue;

            timetaken+=courses[i][0];
            pq.push(courses[i][0]);

            if(courses[i][1]<timetaken){
                //remove the longest time taken
                timetaken-=pq.top();
                pq.pop();
            }

        }  
        return pq.size();
    }
};