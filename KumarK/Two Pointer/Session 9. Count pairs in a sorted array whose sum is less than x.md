//https://www.geeksforgeeks.org/count-pairs-array-whose-sum-less-x/

```
#include <iostream>
using namespace std;

int main() {
int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int x = 7;
		int n = 8;
	int i=0,j=n-1;

	int sum = 0;
	while(i < j){
	    while(i < j && arr[i] + arr[j] >= x)
	    j--;
	    sum+=(j-i);
	    i++;
	}
	cout<<sum<<" ";
	return 0;
}
