## Subarray:- continous and order to be maintained.
### Total subarrays of n elements :- n * (n+1)/2;
## Subsequence:- non continous and ordered
### Total no of subsequnces :- 2^n
## Subarray :- non continous and non-ordered
### total no of subsets :- 2*n

## Q1) https://www.geeksforgeeks.org/minimum-product-subset-array/
## Approach 1:-
#### Use two loops and generate all subsets and find min
## Approach 2:- 


## Q2) https://www.geeksforgeeks.org/maximize-array-sum-after-k-negations-using-sorting/
### Approach 1:-
```
for (int i=1;i<=k;i++){
int mini = max;
  for(int j=0;j<n;j++){
     mini = min(mini,arr[j]);
  }
  if(mini  != 0)
  a[index_mini]  = -a[index_mini];
  else
  return accumulate(arr.begin(),arr.end(),0);
}
return accumulate(arr.begin(),arr.end(),0);

TC:- O(N*k), Sc:- O(1)
```
### Approach 2:-
#### sort the array
```
sort(arr.begin(),arr.end());
for(int i=0;i< n && arr[i] < 0 && k > 0; i++){
  arr[i] = -arr[i];
  k--;
}

sort(arr.begin(),arr.end());
if(k>0 && k%2!=0)
arr[0] = -arr[0];

return accumulate(arr.begin(),arr.end(),0);

TC:- O(n logn)
SC:- O(1)
```






