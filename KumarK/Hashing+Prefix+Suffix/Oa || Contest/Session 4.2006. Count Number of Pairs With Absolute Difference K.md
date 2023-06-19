//https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/description/

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) 
    {
        unordered_map<int,int>s;
        s[nums[0]] = 1;
        int ans = 0;

        for(int i = 1; i<nums.size(); i++)
        {
            if(s.find(nums[i]-k) != s.end())
            {
                ans += s[nums[i]-k];
            }
            if(s.find(nums[i]+k) != s.end())
            {
                ans += s[nums[i]+k];
            }
            s[nums[i]]++;
        }
        return ans;
    }
};
