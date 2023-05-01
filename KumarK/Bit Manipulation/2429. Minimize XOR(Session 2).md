//https://leetcode.com/problems/minimize-xor/description/


```
class Solution {
public:
int setBits(int n){
    int count = 0;
    while(n){
        if(n & 1)
        count++;
        n = (n >> 1);
    }
    return count;
}
    int minimizeXor(int num1, int num2) {
        int sett1 = setBits(num2);
        int sett = __builtin_popcount(num2);
        int ans=0;
        //place "1" i.e setbits(same no of set bits as in num1) from MSB to LSB direction 
        //That will make sure that num1 XOR x is minimum
        //if setbits = no of set bits in num1, then num1 XOR x = 0
        //if setbits < no of set bits in num1, then num1 XOR x will be as minimum as possible
        //if setbits > no of set bits in num1, then we have to place the remaining set bits in x in such a way that num1 XOR x will be as minimum as possible
        for(int i=31;i>=0;i--){
            if((num1 & (1 << i)) && sett > 0){
                ans = ans | (1 << i);
                sett--;
            }
            if(sett == 0)
            return ans;
        }

        //if there are more set bits remaining to be placed in x 
        //place them from LSB to MSB direction making the number x as less larger as possible
        for(int i=0;i<32;i++){
            if((ans & (1 << i)) == 0 && sett > 0){
                ans = ans | (1 << i);
                sett--;
            }
            if(sett == 0)
            return ans;
        }
        return ans;
    }
};
