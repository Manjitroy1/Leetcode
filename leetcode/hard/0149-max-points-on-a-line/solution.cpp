class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // Ay+Bx+C=0
        using t= tuple<int,int,int>;
        map<t,set<int>>mpp;
        int ans=0;
        int n=points.size();
        if(n==1) return 1;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1= points[i][0];
                int y1= points[i][1];

                int x2= points[j][0];
                int y2= points[j][1];

                int a= (x1-x2);
                int b=(y2-y1);
                int c= -1*(b*x1 + a*y1);

                int g=__gcd(abs(a), __gcd(abs(b),abs(c)));
                a/=g;
                b/=g;
                c/=g;

                //we have make unique sign 
                if(a<0 || (a==0 && b<0)){
                    a*=-1;
                    b*=-1;
                    c*=-1;
                }
                
                mpp[{a,b,c}].insert(i);
                mpp[{a,b,c}].insert(j);

            }
        }
        


        for(auto& it:mpp){
            int sz=it.second.size();
            ans= max(ans,sz);
        }
        return ans;
    }

    
};