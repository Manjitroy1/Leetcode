class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9<s) return -1;
        int num=0;
        while(n){
            num*=10;
            if(s<9){
                num+=s;
                s=0;
            }else{
                num+=9;
                s-=9;
            }
            n--;
        }
        return num;
    }
};