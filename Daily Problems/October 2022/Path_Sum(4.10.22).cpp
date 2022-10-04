//https://leetcode.com/problems/path-sum/description/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right){
            if(root->val == targetSum )
            return true;
            return false;
        }
        if(hasPathSum(root->left,targetSum-root->val))
        return true;
        return (hasPathSum(root->right,targetSum-root->val));
    }
};