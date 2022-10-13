
//https://leetcode.com/contest/weekly-contest-314/problems/find-the-original-array-of-prefix-xor/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int>arr;
          arr.push_back(pref[0]);
        if(pref.size() == 1)
            return arr;
        for(int i=1;i<pref.size();i++){
            arr.push_back(pref[i-1] ^ pref[i]);
        }
        return arr;
    }
};