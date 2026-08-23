class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int n=text.size();
        set<string>stt;
        for(int i=0;i<n-1;i++){
            for(int len=1;i+ 2*len<=n;len++){
                if(text.compare(i,len,text,i+len,len)==0){
                    stt.insert(text.substr(i,2*len));
                }
            }
        }
        for(auto& e: stt){
            cout<<e<<" ";
        }
        return stt.size();
        
    }
};