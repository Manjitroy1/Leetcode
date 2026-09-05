class Solution {
  public:
  static int block;
  static bool comp(const vector<int>&q1,const vector<int>&q2){
      int b1=q1[0]/block;
      int b2=q2[0]/block;
      if(b1!=b2) return b1<b2; //according to block size least first
      
      return q1[1]<q2[1]; //large value of r last
  }
    vector<int> solveQueries(vector<int>& arr, vector<vector<int>>& queries, int k) {
        //atleast k frequent in the query
        //Reorder the queries so that consecutive queries have similar l and r.
        //with the help of block size
        //l begin with least bloxk index. r with max value r side ,need compartor
        int n=arr.size();
        block=sqrt(n);
        // store the queries with additional value idx
        int q=queries.size();
        
        vector<int>ans(q,0); // answer to be return
        
        for(int i=0;i<q;i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(),queries.end(),comp);
        int currl=0;
        int currr=-1;
        int good=0;
        unordered_map<int,int>mpp; // help to find disticnt elem that occur at leask k times
        
        for(int i=0;i<q;i++){
            
            int l=queries[i][0]-1; //zero based
            int r=queries[i][1]-1; //zero based
            int idx=queries[i][2];
            
            while(currl>l){//we have to go left for l
                currl--;
                mpp[arr[currl]]++;
                if(mpp[arr[currl]]==k) good++; //from now going to more than k
                
            }
            while(currr<r){
                currr++;
                mpp[arr[currr]]++;
                if(mpp[arr[currr]]==k) good++;
                
            }
            
            while(currl<l){ //we have to move right for l
                if(mpp[arr[currl]]==k) good--; // from now going to less than k
                mpp[arr[currl]]--;
                currl++;
            }
            
            while(currr>r){
                if(mpp[arr[currr]]==k) good--;
                mpp[arr[currr]]--;
                currr--;
            }
        
            ans[idx]=good;
        }
        return ans;
    }
    
};
int Solution::block;
