![WhatsApp Image 2023-01-29 at 22 12 28](https://github.com/vdas01/Leetcode/assets/72196604/fb8e397e-4f6d-488b-bc98-2961936351ce)

```
#include <bits/stdc++.h>
using namespace std;

int main() {
     string search = "abcz", result = "azdb";
     int i=0,j=0;
     int ans = 0;
     int n = search.length(),m = result.length();
     while(i < n && j < n){
         if(search[i] == result[j]){
             i++;
             j++;
         }
         else
         i++;
     }
     ans = m - j;
     cout<<ans<<" ";
}
