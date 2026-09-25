#define ll long long
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int n=s.size();
        ll total=0;
        string ans="";
        for(char& c:s){
            if(isdigit(c)){
                total*=(c-'0');
            }else{
                total++;
            }
        }
        //i got the total length
        //traverse in reverse order
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                int v= s[i]-'0';
                total/=v;
                k%=total;
            }else{
                if(k==0 || k==total){
                    ans+=s[i];
                    return ans;
                }
                total--;
            }
        }
        return ans;
    }
};