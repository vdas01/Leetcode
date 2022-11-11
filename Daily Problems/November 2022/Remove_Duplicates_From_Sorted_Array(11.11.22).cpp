//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=0,j=1;
        while(j<n){
            if(nums[i] == nums[j]){
                j++;
            }
            else{
                int temp = nums[i+1];
                nums[i+1] = nums[j];
                j++;
                i++;
            }
        }
       return i+1;
    }
};