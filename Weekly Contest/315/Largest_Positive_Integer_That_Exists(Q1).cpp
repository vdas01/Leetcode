//https://leetcode.com/contest/weekly-contest-315/problems/largest-positive-integer-that-exists-with-its-negative/

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int>s;
        int num = 0;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(s.count(x*(-1))){
                num = max(abs(x),num);
            }
            else
                s.insert(x);
        }
        if(num == 0)
            return -1;
        return num;
    }
};