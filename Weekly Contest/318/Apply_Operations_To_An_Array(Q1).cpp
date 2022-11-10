//https://leetcode.com/contest/weekly-contest-318/problems/apply-operations-to-an-array/

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i]*=2;
                nums[i+1] = 0;
            }
        }
       vector<int>ans(n,0);
        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i] != 0)
            ans[k++] = nums[i];
        }
       
        return ans;
    }
};
