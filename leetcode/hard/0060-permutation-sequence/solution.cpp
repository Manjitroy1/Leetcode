class Solution {
public:
    string getPermutation(int n, int k) {
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
};