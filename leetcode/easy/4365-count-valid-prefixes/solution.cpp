class Solution {
public:
    int countValidPrefixes(string s) {
        int n=s.size();
        int count=0;
        int zero=0;
        int one =0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                zero++;
            }else{
                one++;
            }
            if( abs(zero-one)<=1) count++;
        }
        return count;
    }
};