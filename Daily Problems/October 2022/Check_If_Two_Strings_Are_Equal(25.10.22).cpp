//https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1,s2;
        for(auto it:word1)
        s1+=it;
        for(auto it1:word2)
        s2+=it1;
        return s1 == s2;
    }
};
