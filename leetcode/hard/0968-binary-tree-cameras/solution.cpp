/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int camera=0;
    int solve(TreeNode* root){
        if(!root) return 2; //leaf nodes left and right will return null which need no camera 

        int l=solve(root->left);
        int r=solve(root->right);

        if(l==0 || r==0){ //if any of child is not covered , need of camera, so place it
            camera++;
            return 1;
        }
        if(l==1 || r==1){//comb 1 1 , 1 2 ,2 1 not camera but covered
            //no need of camera
            return 2;
        }
        return 0; // both 2 2 convered but has no camera
    }
    int minCameraCover(TreeNode* root) {
        //minimum number of cameras
        //three states
        //1-> this node has cmera
        //0-> this node has no camera
        //2-> no camera but still covered but child
        if(!root) return 0;
        int state = solve(root);
        if(state==0) camera++;
        return camera;
    }
};