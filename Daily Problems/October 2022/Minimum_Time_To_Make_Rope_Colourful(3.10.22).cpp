//https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

class Solution {
public:
    int minCost(string colors, vector<int>& need) {
      if(colors.size()==1) return 0;
      if(colors.size()==2){
          if(colors[0] == colors[1])
           return min(need[0],need[1]);
           return 0;
      }
      int first =0,second=1,n = colors.length(),sum=0;
      while(second<n){
          if(colors[first] == colors[second]){
              if(need[first] <= need[second]){
                  sum+=need[first];
                  first=second;
                  second++;
              }
              else{
                  sum+=need[second];
                  second++;
              }
          }
          else{
              first=second;
              second++;
          }
      }
        return sum;
    }
};
