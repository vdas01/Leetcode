//https://leetcode.com/contest/biweekly-contest-84/problems/count-number-of-bad-pairs/
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
      map<long long,long long>m;
        long long int  c=0;
       long long t = ((long long)nums.size()*(long long)(nums.size()-1))/2;
        for(int i=0;i<nums.size();i++){
            m[nums[i]-i]++;
        }
        for(auto it:m){
            t-=(it.second*(it.second-1))/2;
        }
        
        return t;
    }
};
