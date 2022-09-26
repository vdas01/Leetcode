//https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                sum+=nums[i];
        }
        vector<int>ans;
        for(auto it: queries){
            int add = it[0], index = it[1];
            if(nums[index] == 0){
                if(abs(add)%2 == 0){
                    sum+=add;
                    cout<<sum<<"-"<<1<<" ";
                   
                        // ans.push_back(sum);
                }   
            }
            else if(nums[index]%2 == 0){
                if(abs(add)%2 == 0 && add!=0){
                    sum+= add;
                    // ans.push_back(sum);
                    cout<<sum<<"-"<<2<<" ";
                }   
                else if(abs(add)%2 == 1){
                    sum-=nums[index];
                    // ans.push_back(sum);
                    cout<<sum<<"-"<<3<<" ";
                }
            }
            else{
                if(abs(add)%2 != 0){
                    sum+= (nums[index]+add);
                    cout<<sum<<"-"<<4<<" ";
                }
                  // ans.push_back(sum);
            }
            ans.push_back(sum);
         nums[index] += add;
        }
        if(ans.size()<1)
            ans.push_back(0);
        return ans;
    }
};