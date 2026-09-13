class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        //using two pointer
        //s[i]==s[j] i++,j--
        //if not equal find k such that s[i]==s[k] , find k from the right 
        //we have to swap with j and along the path
        //if no match found then s[i] is the odd freq middle one so push toward centre
        int n=s.size();
        int l=0;
        int r=n-1;
        int ans=0;

        while(l<r){
            //both char match nothing to do
            while(l<r && s[l]==s[r]){
                l++;
                r--;
            }
            if(s[l]!=s[r]){
                int k=r;
                while(l<k && s[l]!=s[k]){
                    k--;
                }
                //if we get a value k
                if(l<k){
                    ans+=(r-k);
                    while(k<r){
                        swap(s[k],s[k+1]);
                        k++;
                    }
                    l++;
                    r--;

                }else{//we did not a value k
                    swap(s[l],s[l+1]);
                    ans++;
                }
            }
        }
        return ans;
    }
};