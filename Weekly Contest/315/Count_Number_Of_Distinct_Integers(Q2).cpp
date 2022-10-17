//https://leetcode.com/contest/weekly-contest-315/problems/count-number-of-distinct-integers-after-reverse-operations/

class Solution {
public:
    int reverse(int num){
        int ans = 0;
        while(num>0){
            int a = num%10;
            num=num/10;
            ans = (ans*10)+a;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
      unordered_set<int>s;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
                count++;
            }
            int nenum =nums[i];
            while(nenum%10 == 0)
                nenum/=10;
            nenum = reverse(nenum);
            if(s.find(nenum) == s.end()){
                s.insert(nenum);
                count++;
            }
        }
        return count;
    }
};