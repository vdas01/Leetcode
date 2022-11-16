//https://leetcode.com/problems/guess-number-higher-or-lower/description/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
   int result(int low,int high){
       while(low <= high){
           int mid = low + ((high-low)/2);
           int res = guess(mid);
           if(res == -1)
           high = mid-1;
           else if(res == 1)
           low = mid+1;
           else
           return mid;
       }
       return -1;
   }
    int guessNumber(int n) {
        return result(1,n);
    }
};