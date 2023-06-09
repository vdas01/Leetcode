

### Q1)
### Given list of processes where each value representing memory consuption by the process and given one variable m representing number of processes to be removed.
### We need to delete m number of processes from the list in contiguous manner and return minimum amount of main memory used by all the proccesses running after
### deleting contiguous segment of processes.

#### Example - processes = {10,4,8,13,20}, m = 2;
#### output = 22 [removing 13 and 20 as its consuming large memory]


```
#include <iostream>
using namespace std;
int main() {
   //processes = {10,4,8,13,20}, m = 2
   int arr[] = {10,4,8,13,20};
   int m = 2;
   int total = 0, ans = 999,sum=0;
   for(int i=0;i<5;i++)
   total+=arr[i];
   int i=0,j=0;
   int n = 5;
   while(j < n){
       sum+= arr[j];
       j++;
       if(j-i == m){
           ans = min(ans, total - sum);
           sum-=arr[i];
           i++;
       }
   }
   cout<<ans<<" ";
}

### Q2) Given list of movies, and a variable k representing maximum allowed difference, we need to group the movies into groups. No groups can have movies 
### which has difference amongst them greater than m. We need to return minimum number of groups which follows the condition.

#### Example - movies = [1,5,4,6,8,9,2], k=3;
#### output = 3 [groups-(1,2,4),(5,6,8),(9)]


```
#include <bits/stdc++.h>
using namespace std;
int main() {
     // movies = [1,5,4,6,8,9,2], k=3;
     // 1,2,4,5,6,8,9
   int arr[] = {1,5,4,6,8,9,2};
   int m = 3, n = 7;
   int mini = 999,maxi =0;
   int i=0,j=0;
   sort(arr,arr+n);
   int count = 0;
   while(j < n){
       mini = min(mini,arr[j]);
       maxi = max(maxi, arr[j]);
       j++;
       int diff = maxi - mini;
       while(diff >= m){
          count++;
          i = j;
          mini = 999;
          maxi = 0;
       }
   }
   if(mini != 999 && maxi != 0)
   count++;
   cout<<count<<" ";
}


