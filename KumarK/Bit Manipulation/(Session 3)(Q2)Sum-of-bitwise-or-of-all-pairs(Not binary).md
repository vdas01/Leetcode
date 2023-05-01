//https://www.geeksforgeeks.org/sum-of-bitwise-or-of-all-pairs-in-a-given-array/

A[1,2,3,4] => 001,010,011, 100
int sum =0;
col -> 0  1   2   3   
  0       1   0   1   --->>sum+= total_valid_pairs * (2^row)
  1       0   1   1   ----->>sum+= total_valid_pairs * (2^row)
  2       0   0   0  --->>>sum+= total_valid_pairs * (2^row)
  
  
 ``` 
  #include <bits/stdc++.h>
using namespace std;
int main() {
    int n = 5;
    //1 based indexing
  int arr[] = {-1,1,2,3,4};
  vector<vector<int>> binary_2d(50,vector<int>(n,0));

//col ---> ith index in arr
//row:- bit pos from 0 to 49
  for(int i=1;i<n;i++){
     int num = arr[i];
     //each bit value fig out 
     for(int j=0;j<50;j++){
         int mask = 1<<j;
         int value = num & mask;
         if(value != 0)
         binary_2d[j][i] = 1;
     }
  }
int ans = 0;
  for(int i = 0;i<50;i++){
      int cnt = 0,count_one = 0;
      if(binary_2d[i][1] == 1)
      count_one++;
      for(int j=2;j<n;j++){
          if(binary_2d[i][j] == 0){
              cnt+= count_one;
          }
          else{
              cnt+= (j-1);
              count_one++;
          }
      }
      int total = cnt * (1 << i);
      //pow(2,i) = (1 << i)
      ans += total;
  }
  cout<<ans<<" ";
}
