//https://leetcode.com/problems/count-complete-tree-nodes/

class Solution {
public:
     int lheight(TreeNode* root){
         int height = 0;
         while(root){
             height++;
             root = root->left;
         }
         return height;
     }
     int rheight(TreeNode* root){
         int height = 0;
         while(root){
             height++;
             root = root->right;
         }
         return height;
     }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = lheight(root), rh = rheight(root);
        if(lh == rh)
        return (pow(2,lh)-1);
        else
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};