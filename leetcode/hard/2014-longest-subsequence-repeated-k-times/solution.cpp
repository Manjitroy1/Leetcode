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
    string bfs(string s, int k) {
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
    void dfs(string curr,string& ans,string& s, int k, vector<int>&freq){
        if(curr.size()> ans.size() || (curr.size()==ans.size() && curr>ans)) ans=curr;

        for(char c='a';c<='z';c++){

            if(freq[c-'a']< k) continue;

            curr+=c;
            freq[c-'a']-=k;

            if(check(curr,s,k)){
                dfs(curr,ans,s,k,freq);
            }

            curr.pop_back();
            freq[c-'a']+=k;
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        for(char c:s){
            freq[c-'a']++;
        }
        //for a string to be an answer all char of c must be atleast k times present

        string ans="";
        string curr="";

        dfs(curr,ans,s,k,freq);
        return ans;
    }
};