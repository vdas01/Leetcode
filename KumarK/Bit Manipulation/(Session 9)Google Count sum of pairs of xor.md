```
Given an array 'A' of size 'N' ; find the sum of xor of all pairs of the given array .

1<=N<=100000

1<=a[i]<=100000000

Input :

5

2 7 1 5 8

Output : 2xor7 + 2xor1 + 2xor5 + 2xor8 + 7xor1 + 7xor5 + 7xor8 + 1xor5 + 1xor8 + 5xor8 = 74
```

```
long long int sumXOR(int array[], int length) {
    long long int result = 0;
    for (int i = 0; i < 31; i++) {
        long long int zeroCount = 0, oneCount = 0;

        for (int j = 0; j < length; j++) {
            if (array[j] & (1 << i)) {
                oneCount++;
            }
            else {
                zeroCount++;
            }
        }

        long long int product = zeroCount * oneCount;
        result += (1 << i) * product;
    }
    return result;

    }
```
```
//Python code

class Solution:
    def sumXOR (self, arr, n) : 
        
        sum = 0
        for i in range(0, 32):
            zc = oc = 0
            
            for j in range(n):
                if arr[j] % 2 == 0:
                    zc += 1
                else:
                    oc += 1
                
                arr[j] = arr[j] >> 1
            
            sum += oc * zc * (1 << i)
         
        return sum
```
```
//java code

    public long sumXOR (int arr[], int n) {
    long result = 0;
    for (int i = 0; i < 32; i++) {
        long zeroCount = 0, oneCount = 0;
        for (int j = 0; j < n; j++) {
            if ((arr[j] & (1 << i))!=0)
            {
                oneCount++;
            }
            else
            {
                zeroCount++;
            }
        }
        long product = zeroCount * oneCount;
        result += (1 << i) * product;
    }
    return result;
}
}
```
