class Solution {
    public:
    bool possible(string skill, string station,int mid){
        int n=skill.size();
        int m=station.size();
        int first=0;
        while(station[first]!=skill[0]){
            first++; //first char placed
        }
        int j=1;
        int last=first-1;
        for(int i=first;i<m;i++){
            if(station[i]==skill[j] && (i-last>=mid)){
                j++;
                last=i;

                if(j>=n) return true;
            }
        }
        return j>=n;
    }
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        if(n==1 || n==m) return 0;
        int l=0; //zero gap
        int h= m-n+1; //max possible gap;
        //apply binary search
        int ans=0;
        while(l<=h){
            int mid= (l+h)>>1;
            if(possible(skill,station,mid)){
                ans=h;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
        
    }
};