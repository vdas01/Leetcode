//Return sum of Or of all pairs of an array containing only 0's and 1's

```
#include <iostream>
using namespace std;
int main() {
    int n = 8;
  int arr[] = {0,1,1,0,0,0,1,1};
  int count_one = 0;
  if(arr[0] == 1)
  count_one++;
  int sum=0;
  for(int i=1;i<n;i++){
      int curr_count = 0;
      if(arr[i] == 0){
          curr_count+=count_one;
      }
      else{
             curr_count+=i;
             count_one++;
      }
      sum+=curr_count;
  }
  cout<<sum<<"\n";
}
