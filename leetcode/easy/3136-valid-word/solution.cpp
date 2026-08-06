class Solution {
public:
    bool vowelandcons(string& word){
        bool vow= false;
        bool cons=false;

        for(char c:word){
            if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u'){
                vow= true;
            }
            else if(c=='A' || c=='E' || c=='I'|| c=='O' || c=='U'){
                vow= true;
            }
            else if((c>'a' && c<='z') || (c>'A' && c<='Z')){
                cons=true;
            }
            
        }
        return vow&cons;
    }
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;

        for(char c: word){
            int v= (int)c;
            if((v>47 && v<58) || (v>64 && v<91) || (v>96 && v<123)){
                continue;
            }else{
                return false;
            }
        }
        return vowelandcons(word);
    }
};