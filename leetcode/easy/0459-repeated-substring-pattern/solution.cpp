class Solution {
public:
    void create(string& s, vector<int>&lps){
        int n=s.size();
        int len=0;
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    i++;
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s) {
        //concat s with s 
        //remove first and last index char
        int n=s.size();
        string t = s+s;
        vector<int>lps(n,0);
        create(s,lps);

        int i=1;
        int j=0;
        while(i<(2*n)-1){
            if(t[i]==s[j]){
                i++;
                j++;
                if(j==n){
                    return true;
                    j=lps[j-1];
                }
            }else{
                if(j>=1)
                    j=lps[j-1];
                else{
                    i++;
                }
            }
        }
        return false;
    }
};