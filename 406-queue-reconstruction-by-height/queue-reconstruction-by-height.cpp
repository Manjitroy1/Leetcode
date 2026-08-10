// class SGT{
// public:
//     vector<int>sgt;
//     SGT(int n){
//         sgt.resize(4*n+1);
//     }
//     //build
//     void build(int idx,int low,int high,vector<int>&arr){
//         if(low==high){
//             sgt[idx]=arr[low];
//             return;
//         }
//         int mid= (low+high)>>1;
//         build(2*idx+1,low,mid,arr);
//         build(2*idx+2,mid+1,high,arr);

//         sgt[idx] = min(sgt[2*idx + 1], sgt[2*idx + 2]);
//     }

//     //find
//     int find(int idx,int low,int high,int l,int r){
//         //no overlap.  l r low high    low high l r
//         if(r<low || l>high) return INT_MAX;
//         //complete overlap.  l low high  r
//         if(l<=low && high<=r) return sgt[idx];
//         //partial overlap
//         int mid= (low+high)>>1;

//         int left= find(2*idx+1,low,mid,l,r);
//         int right=find(2*idx+2,mid+1,high,l,r);

//         return min(left,right);
//     }
// };

class Solution {
public:
static bool comp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]<b[1];  //ascending by k position
        }
        return a[0]>b[0];  //descending by height
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);  

        vector<vector<int>>ans;
        ans.push_back(people[0]);

        for(int i=1;i<people.size();i++){
            int h=people[i][0];
            int k=people[i][1];
            ans.insert(ans.begin()+k, people[i]);
        } 
        return ans;
    }
};