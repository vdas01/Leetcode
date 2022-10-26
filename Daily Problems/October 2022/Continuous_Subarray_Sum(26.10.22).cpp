//https://leetcode.com/problems/continuous-subarray-sum/
class Solution {
public:
bool result(vector<long long>ans,vector<int>nums,int i,int n,long long sum,int k){
    if(ans.size()>=2 && sum%k==0) return true;
    if(i>=n && ans.size()>=2 && sum%k == 0)
    return true;
    if(i>=n) return false;
   
    ans.push_back(nums[i]);
    sum+=nums[i];
       if(result(ans,nums,i+1,n,sum,k))
       return true;
   return false;
}
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        vector<long long>ans;
    for(int i=0;i<nums.size();i++){
         if(result(ans,nums,i,nums.size(),0,k))
         return true;
    };
    return false;
    }
};

//Prefix sum 
class Solution {
public:
bool result(vector<long long>ans,vector<int>nums,int i,int n,long long sum,int k){
    if(ans.size()>=2 && sum%k==0) return true;
    if(i>=n && ans.size()>=2 && sum%k == 0)
    return true;
    if(i>=n) return false;
   
    ans.push_back(nums[i]);
    sum+=nums[i];
       if(result(ans,nums,i+1,n,sum,k))
       return true;
   return false;
}
    bool checkSubarraySum(vector<int>& nums, int k) {
          map<int,int>m;
          int ans =0;
          int sum=0,rem=0;
          m[0] = -1;
          for(int i=0;i<nums.size();i++){
              sum+=nums[i];
              rem = sum%k;
            
              if(m.find(rem) != m.end()){
                if(i - m[rem] > 1)
                return true;
              }
              else{
                  m[rem] = i;
              } 
          }
          return false;
    }
};

