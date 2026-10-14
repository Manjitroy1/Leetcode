class Solution {
public:
    bool perfect(long long x){
        long long r = sqrt(x);

        return r*r == x;
    }
    bool solve(long long x){
        // i have to check if 5x^2 +-4 is perfect or not
        if(x<0) return false;
        long long val = 5LL * x* x;
        return perfect(val+4) || perfect(val-4);
    }
    bool threeFibonacciSum(int n) {
        if(n%2) return false;
        //if n/2 is a fibo num then it is true
        return solve(n/2);
        
    }
};