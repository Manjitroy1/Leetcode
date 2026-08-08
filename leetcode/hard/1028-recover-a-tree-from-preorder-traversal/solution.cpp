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
    int idx=0;
    TreeNode* dfs(string& s,int depth){
        int dash=0;
        int i=idx;
        while(i<s.size() && s[i]=='-'){
            dash++;
            i++;
        }
        if(dash!=depth) return nullptr;

        idx=i;
        int val =0;
        while(idx<s.size() && isdigit(s[idx])){
            val= 10*val + s[idx]-'0';
            idx++;
        }
        TreeNode* root= new TreeNode(val);
         
        root->left= dfs(s,depth+1);
        root->right =dfs(s,depth+1);

        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return dfs(traversal,0);  //string, depth
    }
};