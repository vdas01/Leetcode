//https://leetcode.com/contest/biweekly-contest-85/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        for(int i=0;i< blocks.length()-k+1;i++){
            int c=0,black = 0;
            for(int j=i;j<i+k;j++){
                if(blocks[j] == 'W')
                    c++;
                
            }
            ans = min(ans,c);
        
        }
        return ans;
    