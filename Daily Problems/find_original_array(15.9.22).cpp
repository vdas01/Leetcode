//https://leetcode.com/problems/find-original-array-from-doubled-array/
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
      int  n = changed.size();
        if(n%2 == 1) return {};
        sort(changed.begin(),changed.end());
        vector<int>ans;
        map<int,int>m;
        for(int i=0;i<changed.size();i++){
            m[changed[i]]++;
        }
        for(int i=0;i<changed.size();i++){
            if(m[changed[i]] == 0) continue;
            m[changed[i]]--;
            if(m[changed[i]*2] == 0) return {};
            ans.push_back(changed[i]);
            m[changed[i]*2]--;
        }
        return ans;
    }
};