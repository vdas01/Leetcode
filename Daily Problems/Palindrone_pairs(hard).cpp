//https://leetcode.com/problems/palindrome-pairs/submissions/
class Solution {
public:
    bool palindrome(string ans){
        int i=0,j=ans.length()-1;
        while(i <= j){
            if(ans[i] == ans[j]){
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>ans;
        int n = words.size();
        for(int i=0;i<n-1;i++){
            string s1 = words[i];
            for(int j = i+1;j<n;j++){
                string s2 = words[j];
                if(palindrome(s1+s2))
                    ans.push_back({i,j});
                if(palindrome(s2+s1))
                    ans.push_back({j,i});
            }
        }
        return ans;
    }
};