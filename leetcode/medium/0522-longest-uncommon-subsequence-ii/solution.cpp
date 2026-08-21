class Solution {
public:
    bool issubseq(string&a, string& b){
        //is a substring of b
        int n1=a.size(),n2=b.size();
        if(n1>n2) return false;

        int i=0,j=0;

        while(i<n1 && j<n2){

            if(a[i]==b[j]){
                i++;
            }
            j++;
        }
        return i==n1;
    }
    int findLUSlength(vector<string>& strs) {

        int n=strs.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            bool uncommon=true;   //we are checking if i can be a answer if uncommon with all
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(issubseq(strs[i],strs[j])){
                    uncommon=false;
                    break;
                }

            }

            if(uncommon){
                ans=max(ans, (int)strs[i].size());
            }
        }
        return ans;
    }
};