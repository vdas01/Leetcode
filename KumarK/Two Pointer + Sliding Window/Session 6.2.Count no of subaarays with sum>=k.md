//https://ideone.com/KhY14r
```

int findCnt(int arr[], int n, int k)
{
   
    int ans = 0;
 
    int j=0,i=0,sum=0;
    while(j<n){
        sum+=arr[j];
        while(i<=j and sum>=k){
            ans+=n - j;
            sum-=arr[i];
            i++;
        }
        j++;
    }
    return ans;
}
