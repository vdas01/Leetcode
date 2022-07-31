//https://leetcode.com/contest/weekly-contest-304/problems/make-array-zero-by-subtracting-equal-amounts/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int search = true,c=0;
        do{
           sort(nums.begin(),nums.end());
            int mini = INT_MAX;
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0)
                    search = false;
                else if (i==0 && nums[i]==0)
                    search = true;
                if(nums[i]<mini && nums[i]!=0){
                    mini = nums[i];
                    break;
                } 
            }
            if(!search){
                c++;
            for(int i =0;i<nums.size();i++){
                if(nums[i]!=0)
                nums[i]-=mini;
            }
            }
            
        } while(!search);
        return c;
    }
};