//https://leetcode.com/problems/path-sum-ii/
class Solution {
public:
    void result(TreeNode* root,int targetSum,vector<vector<int>>&ans,vector<int>res){
        if(!root) return;
        res.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum == root->val){
                ans.push_back(res);
            }
        }
        else {
            if(root->left)
            result(root->left,targetSum-root->val,ans,res);
            if(root->right)
                result(root->right,targetSum-root->val,ans,res);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>res;
        result(root,targetSum,ans,res);
        return ans;
    }
};