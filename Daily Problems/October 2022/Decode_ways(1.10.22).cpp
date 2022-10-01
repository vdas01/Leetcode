//https://leetcode.com/problems/decode-ways/
class Solution {
public:
int dp[101];
 int check(int i,string s){
     if(dp[i] != -1) return dp[i];
     if(i >= s.length())
     return 1;
     int op1 = s[i]-'0',op2 = 0;
     cout<<"op1:- "<<op1<<" ";
     int ans =0;
     if(i < s.size()-1){
        cout<<"op2:- "<<op2<<" ";
         op2 = (op1*10) + (s[i+1]-'0');
         
     }
     if(op1>0) ans+=check(i+1,s);
     if(op1 > 0 && op2>0 && op2 <=26)
         ans+= check(i+2,s);
     return dp[i] =  ans;
 }
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
       return check(0,s);
    }
};
