//https://leetcode.com/problems/increasing-triplet-subsequence/description/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int first = nums[0],second = INT_MAX;
        int n = nums.size(),maxi=INT_MIN;
        int arr[nums.size()];
        arr[n-1] = 0;
        arr[n-2] = nums[n-1];
        for(int i=n-3;i>=0;i--){
             arr[i] = max(nums[i+1],arr[i+1]);             
        }
        for(int i=1;i<n;i++){
            if(nums[i] < first){
                second = INT_MAX;
                first = nums[i];
            }
            else if(nums[i] > first && nums[i] < second){
            second = nums[i];
             if(arr[i] > second)
             return true;
            }
            else if(nums[i] > second){
                cout<<first<<" "<<second<<" "<<nums[i];
            return true;
            }
        }
        return false;
    }
};
