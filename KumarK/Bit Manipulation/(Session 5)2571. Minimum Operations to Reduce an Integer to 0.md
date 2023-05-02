## Approach 1:-
### Iterate over the number from right and if we get continous one then we will add 2^i to them which convert them into single one and then 
### when we find single one then we will subtract 2^i from it which will lead to 0.

```
#include <iostream>
using namespace std;
int main() {
   int num;
   cin>>num;
   if(num & 1 == 0)
   cout<<0<<" ";
    int c = 0,count = 0;
    bool one = false;
    int ans = 0;
   for(int i =0;i<32;i++){
      
       if(num & (1 << i)){
           c++;
           one = true;
       }
       else {
           if(c > 1){
               count++;
           }
           else if(c == 1)
           ans++;
           c = 0;
       }
   }
   if(c > 1)
   count++;
   ans+=(count*2);
  cout<<ans<<" ";  
}
```

#### 01110 ---> Add 2^i --->10000---->> Subtract 2^i ----->>> 00000.
#### So if continous one are there then two operations and if single one then single operation to make it zero.

## Approach 2:-
### At each bit add 2^i and subtract 2^i and check where no of bits decreases more then do that 
```
class Solution {
public:
    int minOperations(int num) {
         int add_op = 0;
  for(int i=0;i<20;i++){
      if(__builtin_popcount(num + (1 << i)) < __builtin_popcount(num)){
          add_op++;
          num = num + (1 << i);
      }
  }
      int sub_op = __builtin_popcount(num);
      return add_op + sub_op;
    }
};
