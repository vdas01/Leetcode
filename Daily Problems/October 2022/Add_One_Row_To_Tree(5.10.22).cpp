//https://leetcode.com/problems/add-one-row-to-tree/description/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        queue<TreeNode*>q;
        int d = 1;
        q.push(root);
        while(!q.empty()){
            if(d == depth-1)
            break;
            int count = q.size();
            while(count -- > 0){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            }
            d++;
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            TreeNode* leftn = new TreeNode(val);
            leftn->left = temp->left;
            temp->left = leftn;
            TreeNode* rightn = new TreeNode(val);
            rightn->right = temp->right;
            temp->right= rightn;
        }
        return root;
    }
};