//https://leetcode.com/problems/total-cost-to-hire-k-workers/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n = costs.size();
        int left = 0,right = n-1;
        for(int i=0;i<candidates;i++){
            if(left <= right){
            pq.push({costs[i],i});
            left++;
            }
        }
        for(int i=n-1;i>=n-candidates;i--){
            if(left<=right){
            pq.push({costs[i],i});
            right--;
            }
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            auto temp = pq.top();
            pq.pop();
            ans+= temp.first;
            if(temp.second < left && left <= right){
                pq.push({costs[left],left});
                left++;
            }
            else if(temp.second > right && left <= right){
                pq.push({costs[right],right});
                right--;
            }
        }
        return ans;
    }
};