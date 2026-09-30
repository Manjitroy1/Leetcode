class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size();
        //ratio quality
        using p=pair<double,int>;
        vector<p>data;
        for(int i=0;i<n;i++){
            double r=(double)wage[i]/(double)quality[i];
            data.push_back({r,quality[i]});
        }
        sort(data.begin(),data.end()); //sorted in ratio
        priority_queue<int>pq;

        double ans=LLONG_MAX;
        long long sum=0;
        for(int i=0;i<n;i++){
            double r=data[i].first;
            int q=data[i].second;

            sum+=q;
            pq.push(q);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=min(ans,r*(double)sum);
            }

        }
        return ans;
    }
};