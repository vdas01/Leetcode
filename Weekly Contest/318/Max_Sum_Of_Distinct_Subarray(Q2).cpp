//https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<int,int>m;
        long long  sum=0,ans = 0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
           m[nums[i]]++;
        }
        if(m.size() == k)
        ans = sum;
        int start = 0;
        for(int i=k;i<nums.size();i++){
            m[nums[i]]++;
            sum-=nums[start];
            sum+=nums[i];
            
            if(m[nums[start]] == 1)
                m.erase(nums[start]);
            else
                m[nums[start]]--;
            if(m.size() == k)
                ans = max(ans,sum);
            start++;
        }
        return ans;
    }
};


class Solution
{
public:
       long long maximumSubarraySum(vector<int> &nums, int k)
       {
              unordered_map<int, int> mapping;

              long long currentSum = 0;
              long long maximumSum = 0;

              for (int i = 0; i < k; i++)
              {
                     currentSum += nums[i];
                     mapping[nums[i]]++;
              }

              if (mapping.size() == k)
              {
                     maximumSum = currentSum;
              }

              for (int i = k; i < nums.size(); i++)
              {
                     currentSum -= nums[i - k];
                     currentSum += nums[i];

                     mapping[nums[i - k]]--;

                     if (mapping[nums[i - k]] == 0)
                     {
                            mapping.erase(nums[i - k]);
                     }

                     mapping[nums[i]]++;

                     if (mapping.size() == k)
                     {
                            maximumSum = max(currentSum, maximumSum);
                     }
              }

              return maximumSum;
       }
};

