//https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char>s;
        for(int i=0;i<sentence.size();i++){
            s.insert(sentence[i]);
        }
        if(s.size()==26)
        return true;
        return false;
    }
};
