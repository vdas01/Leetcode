//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
class Solution {
public:
    string removeDuplicates(string s) {
         stack<char>st;
         for(int i=0;i<s.length();i++){
             if(st.empty() || st.top() != s[i])
             st.push(s[i]);
             else if(st.top() == s[i])
             st.pop();
         }
         string ans;
         while(!st.empty()){
             ans+=st.top();
             st.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};