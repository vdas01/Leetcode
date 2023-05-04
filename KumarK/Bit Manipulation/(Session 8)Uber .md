//https://www.desiqna.in/12497/uber-sde-oa-bit-manipulation
![q1](https://user-images.githubusercontent.com/72196604/236119004-9c3c2d56-8027-4a3c-88ac-f2f0d822b2c6.jpg)

### Concept 1:-
#### 1) MS set Bit:- 
#### 2) Comapring two numbers using MSB:-
  ##### If two number msb are at diff position then the number having msb at greater position will be greater.
  ###### e.g:- 1000 , 0111 ----> 8 > 7 . 
  ##### If both have msb at same position then having more set bits will be larger
#### 3) Xor and And :- 
 ##### IF we have msb at diff pos. then xor will not be 0  but and will be 0 so xor > and.
 ##### If we have msb at same pos. then xor will be 0 but and will be 1 so and > xor.
 ##### So we have to search for no of pairs having msb at diff pos.
 ##### We can keep a map with key = msb pos. and value = freq and search for each msb.

```

#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;
 
int main() {
 
 
ll n; cin>>n;
vector<ll> ip;
for(int i=0; i<n; i++) {
	ll x; cin>>x;
	ip.push_back(x);
}
 
 
// will store the MSB & the frquency...
 
//            MSB  freq.
unordered_map<int, int> mp1;
 
 
ll cnt=0;  // ans which we return
 
 
for(int i=0; i<n; i++) {
 
	// int msb=mp2[ip[i]]; 
 
 
	// now fig. out the msb of this no. 
	int num=ip[i];
 
	// finding the msb of each no. 
	int msb=0;    int j=0;
	for(int j=0; j<=31; j++) {
 
		int mask=1<<j;
 
		int val= num&mask;
 
		if(val!=0) msb=j;
	}
 
	mp1[msb]++;
 
 
 
for(int j=0; j<=31; j++) {
 
	// these are the bit pos. & we have to check whether at this bit pos. any msbs are there or not. 
	if(mp1.find(j)!=mp1.end() && j!=msb) {
		cnt+=mp1[j];
	}
}
}
 
cout<<cnt<<endl;
 
	return 0;
}
