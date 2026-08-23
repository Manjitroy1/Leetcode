class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        set<string>stt;
        for(int len=1;len<=(n/2);len++){
            int consecutive=0;
            for(int i=0;i+len<n;i++){
                if(text[i]==text[i+len]){
                    consecutive++;
                }else{
                    consecutive=0;
                }

                if(consecutive==len){
                    string echo = text.substr(i,len);
                    stt.insert(echo);
                    consecutive--;
                }
            }
        }
        return stt.size();
        
    }
};