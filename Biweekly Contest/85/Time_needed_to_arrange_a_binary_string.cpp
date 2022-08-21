//https://leetcode.com/contest/biweekly-contest-85/problems/time-needed-to-rearrange-a-binary-string/
class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool rotate = false;
        int count = 0;
        do{
            rotate = false;
            string ans = s;
            int i = 0;
            while(i< s.length()-1){
                if(s[i] == '0' && s[i+1] == '1'){
                    if(!rotate)
                        count++;
                    rotate = true;
                    ans[i] = '1';
                    ans[i+1] ='0';
                    i+=2;
                }
                else
                    i++;
            }
              s = ans;
        }while(rotate);
        return count;
    }
};