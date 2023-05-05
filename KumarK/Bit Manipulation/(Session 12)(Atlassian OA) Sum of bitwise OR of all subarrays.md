//https://www.desiqna.in/12669/atlassian-oa-bit-manipulation-sde1-march-2023

![q1](https://user-images.githubusercontent.com/72196604/236553555-15d92f8d-de41-4d73-846a-7d84c5f99c2d.jpg)
### Concept:-
### Approach 1:-
#### to find no of subarrays having element 3 in it e.g:- [1,2,3,4,5]
#### formula:- (n-i) * (i+1) :--- (5-2) * (2+1) = 9 subarrays
#### But if fails bcoz we count same subarray for multiple indexes

### Approach 2:- 
#### For each bit i  count subarray whose ith bit is not set
#### Then total no of subarrays - no of subarrays whose i bit is not set = no of subarrays whose ith bit is set.


```
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main() {
	// your code goes here
 
	ll n; cin>>n;
	vector<ll> ip; 
	for(int i=0; i<n; i++) {
		ll x; cin>>x;
 
		ip.push_back(x);
	}
 
	ll sum=0;    ll totSub = n*(n+1)/2;
 
	for(int i=0; i<=31; i++) {
 
		// for each bit pos. we will check how many arr. elements are not set for this bit pos. 
		vector<int> temp;
		for(int j=0; j<n; j++) {
			int mask=1<<i;
 
			int val=ip[j] & mask;
			if(val==0) temp.push_back(j);
		}
 
 
		ll cntSubNotSet = 0;   
 
 
		if(temp.size()==0) {
			continue;
		}
 
		ll cnt=1;  // contigious element
 
		// we will check how many contigous element have  bit not set
		for(int j=1; j<temp.size(); j++) {
			if(temp[j]==temp[j-1]+1) cnt++;
			else {
				cntSubNotSet+= (cnt*(cnt+1))/2;
				cnt=1;
			}
		}
 
		cntSubNotSet+=(cnt*(cnt+1))/2; 
 
		// cout<<i<<" "<<cnt<<endl;
 
		ll cntSubSet = totSub-cntSubNotSet;
 
		// cout<<i<<" "<<cntSubSet<<endl;
 
		sum+=cntSubSet*pow(2,i);
	}
 
	cout<<sum<<" ";
	return 0;
}
```
```
 stdin copy
5 
1 2 3 4 5
 stdout copy
71
```
