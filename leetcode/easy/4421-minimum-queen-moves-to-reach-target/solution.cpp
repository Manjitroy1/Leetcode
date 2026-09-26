class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if(source==target) return 0;
        int sr=source[0];
        int sc=source[1];
        int tr=target[0];
        int tc=target[1];
        //same row // same col
        if(sr==tr || sc==tc) return 1;
        //diognal then 1
        if(sr+sc==tc+tr) return 1;
        if(sr-sc == tr-tc) return 1;
        return 2;
        
    }
};