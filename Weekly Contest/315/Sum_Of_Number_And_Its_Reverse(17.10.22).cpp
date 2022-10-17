//https://leetcode.com/contest/weekly-contest-315/problems/sum-of-number-and-its-reverse/
class Solution {
public:
      int reverse(int num){
        int ans = 0;
        while(num>0){
            int a = num%10;
            num=num/10;
            ans = (ans*10)+a;
        }
        return ans;
    }
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0;i<=num;i++){
            if(i + reverse(i) == num)
                return true;
        }
        return false;
    }
};