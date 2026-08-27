class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // odd number can beacame even and then odd
        //even number can reduce to 1 thus lost the track or the original value
        
        priority_queue<int>pq;

        int minval=INT_MAX;
        //twicing the odd ones and storing the minval
        for(int num:nums){
            if(num%2==1){
                num=num*2;
            }
            pq.push(num);
            minval=min(minval,num);
        }

        int mindev=INT_MAX;

        while(true){
            int mxval=pq.top();
            pq.pop();
            mindev=min(mindev,mxval-minval);

            if(mxval%2==1){
                break;
            }
            mxval/=2;
            minval=min(minval,mxval);
            pq.push(mxval);
        }
        return mindev;
        
    }
};