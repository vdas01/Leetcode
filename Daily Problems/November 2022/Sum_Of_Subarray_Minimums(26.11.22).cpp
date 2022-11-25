//https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
         stack<int>st;
         vector<int>left,right;
         int mod = 1e9 + 7;
         int n = arr.size();
         for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
            if(st.empty())
            left.push_back(-1);
            else
            left.push_back(st.top());
            st.push(i);
         }
        while(!st.empty())
        st.pop();
         for(int i = n-1;i>=0;i--){
             while(!st.empty() && arr[st.top()] > arr[i])
             st.pop();
             if(st.empty())
             right.push_back(arr.size());
             else
             right.push_back(st.top());
             st.push(i);
         }
         reverse(right.begin(),right.end());
         long long ans = 0;
         for(int i=0;i<arr.size();i++){
             long long k = (i - (left[i]+1)) + (right[i] - 1 - i) + 1;
             long long p =(long long) (i - (left[i]+1)) *(long long ) (right[i] - 1 - i);
             k+=p;
             ans+= (arr[i] * k)%mod;
             ans = ans%mod;
         }
         return ans;
    }
};
