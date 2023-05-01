Observation:-
If y[i] = 0 && k[i] = 1, then z[i] = 1
If y[i] = 1 && k[i] = 1 , then z[i] = 0/1 but as z should be as small as possible so z[i] = 0
If y[i] = 0 && k[i] = 0 , then z[i] = 0


```
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll ; 
int main() {
 
    ll y ; 
    cin>>y ; 
    ll k ;
    cin>>k ; 
    //start--->yth bit
    //final---> kth bit 
    ll d = 0 ; 
    ll vv = 0 ; 
    for(ll i = 10 ; i>=0 ; i--){
 
 
        ll start = 0 ; 
        int g = (y >> i);
 
        if((g&1)==1){
            //cout<<"1";
            start = 1 ; 
        } else {
            //cout<<"0";
            start = 0 ; 
        }
 
        ll final = 0 ; 
 
        g = (k >> i);
 
        if((g&1)==1){
            //cout<<"1";
            final = 1 ; 
        } else {
            //cout<<"0";
            final = 0 ; 
        }
 
 
        if(start == final){
           //do nothing as by default z is 0
        } else {
 
            if(start==0){
                 //we have add 2^i to z
               // 1 << 1 means 2^1 so (1<<i) means 2^i
                vv = vv | (1<<i);
                //z---> 2^i
 
            } else {
                 //not possible as if y bit is 1 and k bit not equal means 0 but we cannot make k bit 0 
               //as y bit is already 1 
                d = -1;
 
            }
 
        }
 
 
 
    }
 
 
    if(d==-1){
        cout<<d ; 
    } else {
        cout<<vv ; 
    }
 
 
    return 0 ; 
 
 
}
