class Solution {
public:
    
    int recc(int n,unordered_map<int,int>&mpp){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;

        // int ans=INT_MAX;
        if(mpp.count(n)) return mpp[n];


       int a= n%2 + 1 + recc(n/2,mpp);
       int b= n%3 + 1 + recc(n/3,mpp);
        return mpp[n] = min(a,b);
    }
    
    int minDays(int n) {
        // return recc(n);
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        unordered_map<int,int>mpp;
        return recc(n,mpp);
    }
};