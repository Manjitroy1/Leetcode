class Solution {
public:
    bool check(string str,string s, int k){
        int n=s.size();
        int m=str.size();
        int l=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==str[l]){
                l++;
                if(l>=m){
                    cnt++;
                    l=0;
                    if(cnt>=k) return true;
                }
            }
        }
        return false;
        
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        string first="";
        if(k>n) return first;
        queue<string>q;
        q.push(first);
        string ans="";

        while(!q.empty()){
            string str = q.front();
            // ans=max(ans,str);
            q.pop();

            for(char c='a';c<='z';c++){
                string newstr =str;
                newstr+=c;
                if(check(newstr,s,k)){
                    q.push(newstr);
                    ans=newstr;
                }
            }
        }
        return ans;
    }
};