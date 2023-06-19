//https://leetcode.com/contest/biweekly-contest-103/problems/find-the-prefix-common-array-of-two-arrays/

```
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        unordered_set<int>s1,s2;
        int count=0;
        for(int i=0;i<nums1.size();i++){
            if(s2.find(nums1[i]) != s2.end())
                count++;
            s1.insert(nums1[i]);
            if(s1.find(nums2[i]) != s1.end())
                count++;
            s2.insert(nums2[i]);
            v.push_back(count);
        }
        return v;
    }
};
