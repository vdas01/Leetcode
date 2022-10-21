//https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
           if(m[nums[i]]>0){
               if(abs((m[nums[i]]-1)-i) <=k)
               return true;
               else
               m[nums[i]] = i+1;
           }
           else
           m[nums[i]] = i+1;
       }
       return false;
    }
};


