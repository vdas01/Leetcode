//https://leetcode.com/problems/path-sum-iii/
class Solution {
public:
  void result(TreeNode* root,long long targetSum,vector<int>res,long long &count){
        if(!root) return;
            if(targetSum == root->val){
                count++;
            }
            if(root->left)
            result(root->left,targetSum-root->val,res,count);
            if(root->right)
                result(root->right,targetSum-root->val,res,count);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0;
      long long count = 0;
        vector<int>res;
        result(root,targetSum,res,count);
        count+=pathSum(root->left,targetSum);
        count+=pathSum(root->right,targetSum);
        return count;
    }
};