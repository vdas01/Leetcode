//https://leetcode.com/problems/make-the-string-great/description/

class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
          if(!st.empty() && (int(s[i])+32 == int(st.top()) || int(st.top())+32 == int(s[i])))
          st.pop();
          else
          st.push(s[i]);
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