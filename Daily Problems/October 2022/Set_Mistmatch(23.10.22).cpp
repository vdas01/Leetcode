//https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>s;
        vector<int>ans;
        int sum=0,dup;
        for(int i=0;i<nums.size();i++){
            int p=s.size();
            s.insert(nums[i]);
            if(s.size() == p){
            ans.push_back(nums[i]);
            dup = nums[i];
            }
            sum+=nums[i];
        }
        int n = nums.size();
        ans.push_back((((n*(n+1))/2)-sum)+dup);
        return ans;
    }
};
