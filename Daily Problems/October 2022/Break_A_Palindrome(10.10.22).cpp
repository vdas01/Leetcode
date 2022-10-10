//https://leetcode.com/problems/break-a-palindrome/description/
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if(n==1) return "";
        if(n%2==0){
        for(int i=0;i<n;i++){
            if(i==n-1 && palindrome[i] == 'a')
            palindrome[i] = 'b';
            else if(palindrome[i] == 'a')
            continue;
            else{
                palindrome[i] = 'a';
                break;
            } 
        }
    }
    else{
      
        for(int i=0;i<n;i++){
            if(i == (int)n/2)
            continue;
           else if(i == n-1 && palindrome[i] == 'a')
            palindrome[i] = 'b';
            else if(palindrome[i] == 'a')
            continue;
            else{
                palindrome[i] = 'a';
                break;
            }
        }
    }
        return palindrome;
    }
};
