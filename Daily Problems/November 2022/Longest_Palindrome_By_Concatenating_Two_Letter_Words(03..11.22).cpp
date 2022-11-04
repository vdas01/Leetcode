//https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        int ans = 0;
        bool f = false;
        for(auto it: m){
             string s = it.first;
             string p = s;
             reverse(p.begin(),p.end());
             if(p == s){
                 ans += it.second/2;
                 if(it.second%2)
                 f = true;
             }
             else{
                 if(m.count(p)){
                   ans+= min(m[p],it.second);
                   m.erase(p);
                 }
             }
        }
        ans = ans*4;
        if(f)
        ans = ans+2;
        return ans;
    }
};