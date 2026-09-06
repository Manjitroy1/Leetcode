class Solution {
public:
    int countRotations(string s, int k) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            s.push_back(s[0]);
            s.erase(0,1);

            int cnt=0;
            for(int j=0;j<n-1;j++){
                if(s[j]==s[j+1]){
                    cnt++;
                }
            }
            if(cnt==k){
                ans++;
            }
        }
        return ans;
        
    }
};