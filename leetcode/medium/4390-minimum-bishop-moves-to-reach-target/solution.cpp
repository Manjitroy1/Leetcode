class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int x1=source[0];
        int y1=source[1];
        int sum1=x1+y1;
        int p1=(x1+y1)%2;
        
        int x2=target[0];
        int y2=target[1];
        int sum2=x2+y2;
        int p2=(x2+y2)%2;

        if(p1 ^ p2) return -1; //diff color 
        //check all the diagonal
        if(sum1==sum2) return 1;
        if(x1+ (8-y1) == (x2+ (8-y2))) return 1;
        else return 2;
    }
};