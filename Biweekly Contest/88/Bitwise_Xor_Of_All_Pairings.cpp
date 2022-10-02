//https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m = nums2.size();
        if(n%2==0 && m%2==0)
        return 0;
        if(n%2 == 0 && m%2!=0){
            int ans=0;
            for(int i=0;i<nums1.size();i++){
                ans^=nums1[i];
            }
            return ans;
        }
        else if(m%2==0 && n%2!=0){
            int ans =0;
            for(int i=0;i<nums2.size();i++)
                ans^=nums2[i];
            return ans;
        }
       else{
           int ans=0;
            for(int i=0;i<n;i++)
            ans^=nums1[i];
            for(int i=0;i<m;i++)
            ans^=nums2[i];
            return ans;
       }
       return 0;
    }
};