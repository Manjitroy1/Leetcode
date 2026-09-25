class Solution {
public:
    char kthCharacter(int k) {
        //initially have a
        //a ab abbc abbcbccd exponentially increasing
        string s="a";
        while(s.size()<k){
            string temp="";
            for(char& c:s){
                int v=c-'a';
                v+=1;
                v%=26;
                temp+=('a'+v);
            }
            s+=temp;
        }
        return s[k-1];
    }
};