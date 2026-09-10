# Binary Tree Cameras

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

You are given the `root` of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

Return  *the minimum number of cameras needed to monitor all nodes of the tree*.

 

 **Example 1:** 

```
Input: root = [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.

```

 **Example 2:** 

```
Input: root = [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

```

 

 **Constraints:** 

- The number of nodes in the tree is in the range [1, 1000].
- Node.val == 0

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 21.4 MB (beats 68.17%)  
**Submitted:** 2026-09-10T12:58:22.449Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/binary-tree-cameras/)