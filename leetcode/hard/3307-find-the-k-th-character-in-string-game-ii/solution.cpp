class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int n=operations.size();
        long long len =1;
        int last=0;
        while(last<n && len<k){
            len*=2;
            last++;
        }

        int cnt=0;
        char ans='a';

       for(int i=last-1;i>=0;i--){
            long long half= len/2;
            if(k>half){
                if(operations[i]){
                    cnt++;
                    cnt%=26;
                }
                k-=half;
                len=half;
            }
       }
       return 'a'+cnt;
    }
};