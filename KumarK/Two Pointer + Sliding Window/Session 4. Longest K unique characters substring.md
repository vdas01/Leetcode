//https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

```
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    int n = s.length();
    map<int,int>m;
    int i =0,j=0;
    int ans = -1;
    while(i< n && j < n){
        m[s[j]]++;
        if(m.size() == k)
        ans = max(ans,(j-i)+1);
        j++;
        while(i < n && m.size() > k){
            m[s[i]]--;
            if(m[s[i]] == 0)
            m.erase(s[i]);
            i++;
        }
    }
    return ans;
    }
};
