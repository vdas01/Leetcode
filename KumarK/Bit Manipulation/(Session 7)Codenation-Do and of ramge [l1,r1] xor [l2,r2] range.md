

https://www.desiqna.in/11229/triology-codenation-coding-sde-set-2023-hard-manipulation![q2](https://user-images.githubusercontent.com/72196604/236113671-c12d2964-2b8b-4764-a4a5-e49a08258232.jpeg)
![q1](https://user-images.githubusercontent.com/72196604/236113678-052df29e-932a-483a-a0fd-c34e6746c503.jpeg)
![q2](https://user-images.githubusercontent.com/72196604/236113687-106faa0e-ca52-491b-b8da-d07f1748efcd.jpeg)
![q3](https://user-images.githubusercontent.com/72196604/236117803-47727bed-cf08-4833-b74d-5841d1f092fc.jpeg)


```
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
ll a[200000+5];
ll ok[200000+5][50];
ll sum[200000+5][50];
ll k[55] ;
ll kk(ll x,ll y){
    
    ll vv = abs(x-y)+1;
    ll rr = 0 ; 
    ll i = 31 ; 
    while(i>=0){
        
        ll gg = abs(sum[y][i]-sum[x-1][i]);
        
        if(gg==vv){
            
            rr = ((rr) | (k[i]));
            
        }
        
        
        i--;
    }
    
    //cout<<"\n";
    //cout<<"\n";
    return rr ; 
    
}

int main() {
    
    ll n;
    cin>>n ; 
    ll i = 1 ; 
    while(i<=n){
        cin>>a[i];
        i++;
    }
    
    k[0] = 1 ; 
    i = 1 ; 
    while(i<=50){
        k[i] = (2*k[i-1]);//poewer...of 2....
        i++;
    }
    
    
    int j = 1 ; 
    while(j<=n) {
        for (int i = 31; i >= 0; i--) 
        { 
            int k = a[j] >> i; 
            if (k & 1) {
                //cout << "1";
                ok[j][i] = 1 ; 
            } 
            else{
                //cout << "0";
                }
            
        } 
    j++;
    }
    
    j = 1 ; 
    while(j<=n) {
        for (int i = 0; i <= 31; i++) 
        { 
            sum[j][i] = sum[j-1][i] + ok[j][i];
            
        } 
    j++;
    }
    
    ll q ; 
    cin>>q ;
    
    i = 1 ; 
    while(i<=q){
        ll l1,r1,l2,r2 ; 
        cin>>l1>>r1;
        cin>>l2>>r2;
        //cout<<l1;cout<<"\n";
        ll v2 = kk(l1,r1);
        ll v5 = kk(l2,r2);
        
        //cout<<v2<<" "<<v5 ; 
        
        ll rr = ((v2)^(v5));
        cout<<rr ;
        i++;
    }
    
    
    
    
    
/*
3
3 1 7 
1
1 1 3 3 

9
8 6 5 9 7 7 9 3 8 
1
3 5 5 5 

*/
    
    
    
    
    
    
    
    
    return 0 ; 
}
