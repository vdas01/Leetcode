//https://leetcode.com/problems/reverse-words-in-a-string/description/

class Solution {
public:
string& rightTrim(string& str, string& chars)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
string& leftTrim(string& str, string& chars)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

    string reverseWords(string s) {
        int n = s.length();
        stack<char>st;
       string ans,p;
       for(int i=0;i<n;i++){
          
       st.push(s[i]);
       }
       while(!st.empty()){
           char t = st.top();
           st.pop();
           if(t == ' ' && p != ""){
               reverse(p.begin(),p.end());
               ans+=p;
              
               ans+= ' ';
               p="";
           }
           else if(t != ' ')
           p+=t;
       }
         string chars_to_trim = " ";
       if(p.length()>0)
       reverse(p.begin(),p.end());
       ans+=p;
       leftTrim(ans, chars_to_trim);
       rightTrim(ans, chars_to_trim);
       return ans;
    }
};