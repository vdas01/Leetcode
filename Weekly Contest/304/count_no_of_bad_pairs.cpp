//https://leetcode.com/contest/biweekly-contest-84/problems/count-number-of-bad-pairs/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<long long,long long>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]-i]++;
        }
      long long total = (nums.size()*(nums.size()-1))/2;
        for(auto it:m){
            total -= (it.second*(it.second-1))/2;
        }
        return total;
    }
};