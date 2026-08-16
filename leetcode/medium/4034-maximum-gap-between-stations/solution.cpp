class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        int j=0;

        for(int i=0;i<m && j<n;i++){
            if(station[i]==skill[j]){
                left[j]=i;
                j++;
            }
        }
        j=n-1;
        
        for(int i=m-1;i>=0 && j>=0;i--){
            if(station[i]==skill[j]){
                right[j]=i;
                j--;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(ans, right[i]-left[i-1]);
        }
        return ans;
    }
};