![WhatsApp Image 2023-01-30 at 12 14 09](https://github.com/vdas01/Leetcode/assets/72196604/82c0fcf3-4e68-4458-a1d5-5c1d36fdf32a)
```
#include <bits/stdc++.h>
using namespace std;
int main() {
     // prices = [1,2,7,7,4,3,6], k=3;
     int arr[] = {1,2,7,7,4,3,6};
     int k = 3;
     int ans = 0, n = 7;
     int sum =0 ;
    map<int,int>m;
     int i =0,j=0;
     while(j < n){
         sum+=arr[j];
         m[arr[j]]++;
          j++;
         if(m.size() == k && j-i  == k){
             ans = max(ans,sum);
             sum-=arr[i];
             m[arr[i]]--;
             if(m[arr[i]] == 0)
             m.erase(arr[i]);
             i++;
            
         }
         while(j-i > m.size()){
            sum-=arr[i];
            m[arr[i]]--;
            if(m[arr[i]] == 0)
            m.erase(arr[i]);
            i++;
         }
     }
     cout<<ans<<" ";
}
