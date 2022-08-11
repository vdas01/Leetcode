class Solution {
public:
    bool result(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i==n)
            return true;
        if(dp[i] != -1) return dp[i];
        bool res= false;
        if(i+1 < n && nums[i] == nums[i+1]){
            res = result(nums,i+2,n,dp);
            if(i+2 < n && nums[i] == nums[i+2])
                res = res || result(nums,i+3,n,dp);
        }
        if(i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1)
            res = res || result(nums,i+3,n,dp);
        return dp[i] = res;
    }
    bool validPartition(vector<int>& nums) {
        if(nums.size()==2)
            return nums[0] == nums[1];
        vector<int>dp(nums.size(),-1);
      return  result(nums,0,nums.size(),dp);
    }
};
