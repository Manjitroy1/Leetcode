struct Node{
    Node* lists[26]={};
    bool flag=false;

    bool containkey(char c){
        return lists[c-'a'] != nullptr;
    }
    void put(char c, Node* node){
        lists[c-'a'] = node;
        return;
    }
    Node* next(char c){
        return lists[c-'a'];
    }
    void setend(){
        flag=true;
        return;
    }
    bool isend(){
        return flag;
    }
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->next(word[i]);
        }
        node->setend();
    }
    bool dfs(Node* node, int idx, string& word){
        if(idx>=word.size()){
            return node->isend();
        }
        //normal charecter
        if(word[idx]!='.'){
            if(!node->containkey(word[idx])){
                return false;
            }
            return dfs(node->next(word[idx]), idx+1,word);
        }

        //if char is dot try all possibilieties
        for(int i=0;i<26;i++){
            if(node->lists[i]!=nullptr){
                //if a char then try this as a dot replacement
                if(dfs(node->lists[i], idx+1,word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool search(string word) {
        return dfs(root,0,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */