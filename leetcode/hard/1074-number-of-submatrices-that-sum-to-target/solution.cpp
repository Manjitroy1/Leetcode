class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //column compression to evenuall convert into single column
        int n=matrix.size();
        int m=matrix[0].size();
        int cnt=0;

        for(int top=0;top<n;top++){
            vector<int>col(m,0);

            for(int bottom=top;bottom<n;bottom++){
                
                for(int j=0;j<m;j++){
                    col[j]+=matrix[bottom][j];
                }

                unordered_map<int,int>mpp;
                int sum=0;
                mpp[0]=1;

                for(int j=0;j<m;j++){
                    sum+=col[j];
                    int need= sum-target;

                    if(mpp.count(need)){
                        cnt+=mpp[need];
                    }
                    mpp[sum]++;
                }

            }
        }
        return cnt;
    }
};