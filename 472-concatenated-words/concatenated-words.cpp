struct Node{
    Node* links[26] = {};
    bool flag =false;

    bool containskey(char c){
        return links[c-'a'] != nullptr;
    }
    Node* get (char c){
        return links[c-'a'];
    }
    void put(char c,Node* node){
        links[c-'a'] = node;
        return ;
    }
    void setend(){
        flag=true;
        return;
    }
    bool isend(){
        return flag;
    }
};
class Trie{
public:
    Node* root;

    Trie(){
        root= new Node();
    }
    void insert(string& s){
        int cnt=0;
        int pos =-1;
        Node* node = root;

        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(!node->containskey(c)){
                node->put(c,new Node());
            }
            if(node->isend()){
                cnt++;
                pos=i;
            }
            node = node->get(c);
        }
        node->setend();
    }

    bool search(string& s){
        Node* node = root;
        for(char& c:s){
            if(!node->containskey(c)){
                return false;
            }
            node=node->get(c);
        }
        return node->isend();
    }
    bool startwith(char& c){
        Node* node=root;
        return node->containskey(c);
    }
};
class Solution {
public:

    static bool comp(string& a,string& b){
        return a.size() < b.size();
    }
    // Trie first; //object of trie
    // Node* root = first.root;

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        //build the trie
        sort(words.begin(),words.end(),comp);
        vector<string>ans;

        unordered_set<string>st;

        for(string& w:words){
            int n=w.size();
            vector<int>dp(n+1,-1);
            // dp[i] = cnt of prefix of length i can be splitted
            dp[0]=0;
            for(int i=0;i<n;i++){
                if(dp[i]==-1) continue;
                string temp="";

                for(int j=i;j<n;j++){
                    temp+=w[j];

                    if(st.count(temp)){
                        dp[j+1] = max(dp[j+1],dp[i]+1);
                    }
                }
            }
            if(dp[n]>=2){
                ans.push_back(w);
            }
            st.insert(w);
        }
        return ans;
    }
};