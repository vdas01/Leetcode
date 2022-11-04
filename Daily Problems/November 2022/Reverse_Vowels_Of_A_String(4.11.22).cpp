//https://leetcode.com/problems/reverse-vowels-of-a-string/description/

class Solution {
public:
    string reverseVowels(string s) {
        int start =0,end = s.length()-1;
        int n = s.length();
        while(start < end){
            while(start < n && s[start] != 'a' && s[start] != 'e' && s[start] != 'i' && s[start] != 'o' && s[start] != 'u' && s[start] != 'A' && s[start] != 'E' && s[start] != 'I' && s[start] != 'O' && s[start] != 'U' )
            start++;
              while(end >= 0 && s[end] != 'a' && s[end] != 'e' && s[end] != 'i' && s[end] != 'o' && s[end] != 'u' && s[end] != 'A' && s[end] != 'E' && s[end] != 'I' && s[end] != 'O' && s[end] != 'U' )
            end--;
            if(start < end){
               
            char p = s[start];
            s[start] = s[end];
          
            s[end] = p;
          
            start++;
            end--;
            }
        }
        return s;
    }
};
