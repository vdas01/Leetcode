//https://leetcode.com/problems/count-and-say/description/
class Solution {
public:
    string countAndSay(int n) {
         string p = "";
         p+='1';
         n--;
         string ans;
         while(n){
             int count=1;
             char last =p[0];
             for(int i=1;i<p.length();i++){
                 if(last == p[i])
                 count++;
                 else{
                     ans+= ""+to_string(count)+last;
                     last = p[i];
                     count=1;
                 }
             }
             if(count)
             ans+= ""+to_string(count)+last;
             p=ans;
             ans.clear();
             n--;
         }
        return p;
    }
};
