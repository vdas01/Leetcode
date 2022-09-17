//https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/
//1) Without dp:-
class Solution {
public:
    int result(int i,vector<int>nums,vector<int> multipliers,int s){
        int e = nums.size()-(i-s)-1;
        if(i == multipliers.size()) return 0;
        int ans1 = nums[s] * multipliers[i] + result(i+1,nums,multipliers,s+1);
        int ans2 = nums[e]*multipliers[i] + result(i+1,nums,multipliers,s);
        return max(ans1,ans2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int ans = result(0,nums,multipliers,0);
        return ans;
    }
};
//2)
class Solution {
public:
            // vector<vector<int>>dp(1001,vector<int>(1001,-1));
        int dp[1001][1001];

    int result(int i,vector<int>nums,vector<int> multipliers,int s){
        int e = nums.size()-(i-s)-1;
        if(i == multipliers.size()) return 0;
        if(dp[i][s] != -1) return dp[i][s];
        int ans1 = nums[s] * multipliers[i] + result(i+1,nums,multipliers,s+1);
        int ans2 = nums[e]*multipliers[i] + result(i+1,nums,multipliers,s);
        return dp[i][s] = max(ans1,ans2);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(dp,-1,sizeof dp);
        int ans = result(0,nums,multipliers,0);
        return ans;
    }
};

