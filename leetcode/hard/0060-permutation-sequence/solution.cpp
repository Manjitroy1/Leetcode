class Solution {
public:

string sovle(int n, int k) {
        string arr="";
        for(int i=1;i<=n;i++){
            // arr.push_back(i);
            arr+=(i+'0');
        }
        string ans="";
        do{
            if(k==1) ans=arr;
            k--;
        }while(k && next_permutation(arr.begin(),arr.end()));
        return ans;
    }
    int next(vector<int>&arr,int pos){
        //first indx that is not used
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                cnt++;
                if(cnt==pos){
                    arr[i]=0;
                    return i+1;
                }
            }
        }
        return 0;
    }
    string solveopt(int n,int k){
        vector<int>fact(n);
        fact[0]=1;
        for(int i=1;i<n;i++){
            fact[i]=i* fact[i-1];
        }

        string s="";
        for(int i=1;i<=n;i++){
            s+=(i+'0');
        }

        k--; // zero based

        string ans="";
        for(int i=n;i>=1;i--){
            int pos = k/fact[i-1];
            ans+= s[pos];
            s.erase(s.begin()+pos);
            k%=fact[i-1];
        }
        return ans;
       
    }
    string getPermutation(int n, int k) {
        // return solve(n,k);
        return solveopt(n,k);
    }
};