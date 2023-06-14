//https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
```
int s=0,e=0;
        while(e<n)
        {
            if(arr[e]==0)
            {
                e++;
            }
            else
            {
                swap(arr[s],arr[e]);
                s++;
                e++;
            }
