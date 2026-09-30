struct Node{
    char leftchar;
    char rightchar;
    int pref;
    int suff;
    int best;

};
class Segment{
public:
    vector<Node>sgt;
    Segment(int n){
        sgt.resize(4*n+1);
    }
    Node merge(int idx1,int idx2,int leftlen,int rightlen){
        Node node1= sgt[idx1];
        Node node2= sgt[idx2];


        Node ans;
        ans.best=max(node1.best,node2.best); //may be updated

        if(node1.rightchar==node2.leftchar){
            ans.best=max(ans.best, node1.suff + node2.pref);
        }

        ans.leftchar=node1.leftchar;
        ans.rightchar=node2.rightchar;

        //what about updated pref and suff
        ans.pref=node1.pref;
        ans.suff=node2.suff;

        if(node1.rightchar==node2.leftchar){
            if(node1.pref==leftlen) ans.pref=leftlen + node2.pref;
            if(node2.suff==rightlen) ans.suff=rightlen + node1.suff;  
        }
        return ans;

    }
    void build(int idx,int low,int high,string& s){
        if(low==high){
            Node leaf;
            leaf.leftchar=s[low];
            leaf.rightchar=s[low];
            leaf.pref=1;
            leaf.suff=1;
            leaf.best=1;
            sgt[idx]=leaf;
            return ;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,s);
        build(2*idx+2,mid+1,high,s);
        
        int leftlen=mid-low+1;
        int rightlen=high-mid;

        sgt[idx]=merge(2*idx+1,2*idx+2,leftlen,rightlen); //merge those two segment

    }
    void update(int idx,int low,int high, int pos,char c){
        if(low==high){
            // we reach at the pos
            sgt[idx].leftchar=c;
            sgt[idx].rightchar=c;
            return;
        }
        int mid= low+(high-low)/2;
        if(pos<=mid) update(2*idx+1,low,mid,pos,c);
        else update(2*idx+2,mid+1,high,pos,c);

        int leftlen=mid-low+1;
        int rightlen=high-mid;

        sgt[idx]=merge(2*idx+1,2*idx+2,leftlen,rightlen);
    }

};
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n=s.size();
        int q=queryCharacters.size();
        
        Segment first(n);
        first.build(0,0,n-1,s);

        vector<int>ans;
        for(int i=0;i<q;i++){
            //update
            int pos=queryIndices[i];
            char c=queryCharacters[i];
            first.update(0,0,n-1,pos,c);
            ans.push_back(first.sgt[0].best);
        }
        return ans;
    }
};