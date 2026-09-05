class Solution {
public:
    bool check(string& res){
        int l=0;
        int r=res.size()-1;
        while(l<=r){
            if(res[l]!=res[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isPalindromic(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            char c=s[i];
            int val=(int)c; //go tthe ascii value 
            //we need 8 bit repsentation]
            for(int j=7;j>=0;j--){
                int bit= ((val>>j) & 1)? 1:0;
                res+=to_string(bit);
            }
        }
        return check(res);
    }
};