//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
class Solution {
public:
unordered_set<int>s;
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
   
        if(s.find(k-root->val) != s.end())
        return true;
        s.insert(root->val);
        if(findTarget(root->left,k))
        return true;
        if(findTarget(root->right,k))
        return true;
        return false;
    }
};
