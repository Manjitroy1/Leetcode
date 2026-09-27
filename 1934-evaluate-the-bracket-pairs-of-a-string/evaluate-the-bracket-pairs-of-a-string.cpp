class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto& node:knowledge){
            mpp[node[0]]=node[1];
        }
        int i=0;
        int n=s.size();
        string ans="";
        
        while(i<n){

            if(s[i]=='('){
                i++;
                string temp="";
                while(i<n && s[i]!=')'){
                    temp+=s[i];
                    i++;
                }
                if(mpp.count(temp)){
                    ans+=mpp[temp];
                }else{
                    ans+="?";
                }

            }else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};