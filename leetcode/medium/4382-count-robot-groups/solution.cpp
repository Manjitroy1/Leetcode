class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        if(n==1) return 1;
        int ans=1;
        
        int last=speed[n-1];  
        for(int i=n-2;i>=0;i--){
            if(speed[i]<=last && (position[i+1]-position[i]) > distance){
                ans++;
                last=speed[i];
            }
        }
        return ans;
    }
};