class Solution {
public:
    int mod = 1e9+7;

    int countVowelPermutation(int n) {
        // int preva=1;
        // int preve=1;
        // int previ=1;
        // int prevo=1;
        // int prevu=1;
        vector<int>prev(5,1); //a e i o u
        if(n==1) return 5;
        // if(n==2) return 10;

        for(int i=2;i<=n;i++){
            // int curra=0;
            // int curre=0;
            // int curri=0;
            // int curro=0;
            // int curru=0;
            vector<int>curr(5,0);

            //a will generate e;
            curr[1]= (curr[1] + prev[0]) % mod;

            //e will generate i and a
            // curri+=preve;
            // curra+=preve;

            curr[2]= (curr[2] + prev[1]) % mod;
            curr[0]= (curr[0] + prev[1]) % mod;


            //i will generate a e o u
            // curra+=previ;
            // curre+=previ;
            // curro+=previ;
            // curru+=previ;

            curr[0]= (curr[0] + prev[2]) % mod;
            curr[1]= (curr[1] + prev[2]) % mod;
            curr[3]= (curr[3] + prev[2]) % mod;
            curr[4]= (curr[4] + prev[2]) % mod;


            //o will generate i u
            // curri+=prevo;
            // curru+=prevo;

            curr[2]= (curr[2] + prev[3]) % mod;
            curr[4]= (curr[4] + prev[3]) % mod;


            //u will generate a
            // curra+=prevu;
            curr[0]= (curr[0] + prev[4]) % mod;



            //restore
            // preva=curra;
            // preve=curre;
            // previ=curri;
            // prevo=curro;
            // prevu=curru;
            prev=curr;
        }
        int sum =0;
        // return (preva+preve+previ+prevo+prevu);
        for(int i=0;i<5;i++){
            sum = (sum + prev[i])%mod;
        }
        return sum;

    }
};