class Solution {
public:
    int solve(int l,int h,string& text){
        if(l>h) return 0;
        if(l==h) return 1;
        
        // int ans=0;
        // int take=0;
        
        for(int i=l;i<=(l+h)/2;i++){
            int j=h+l-i;
            int len = i-l+1;
            if(text.compare(l,len,text,j,len) ==0){
                return (2+solve(i+1,j-1,text));
            }
        }
        return 1;
    }
    int longestDecomposition(string text){
        int l=0;
        int h=text.size()-1;
        return solve(l,h,text);
        
    }
};