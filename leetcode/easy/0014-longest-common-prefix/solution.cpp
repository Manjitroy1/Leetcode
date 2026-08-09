struct Node{
    Node* links[26]= {};
    bool flag=false;
    int size=0;

    bool containskey(char c){
        return links[c-'a'] != nullptr;
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void put(char c, Node* node){
        links[c-'a'] = node;
        return;
    }
    void setend(){
        flag=true;
        return;
    }
    bool isend(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node= root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
                node->size++;
            }
            node = node->get(word[i]);
        }
        node->setend();
    }
};
 
class Solution {
public:
    Trie first;
    string longestCommonPrefix(vector<string>& strs) {
        for(string& s:strs){
            first.insert(s);
        }
        Node* node = first.root;
        
        string ans="";

        while(node->size==1 && !node->isend()){
           for(int i=0;i<26;i++){
                if(node->links[i]!=nullptr){
                    ans+=(i+'a');
                    node= node->links[i];
                    break;
                }
           }
        }
        return ans;
    }
};