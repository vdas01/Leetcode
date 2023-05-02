![IMG-20221007-WA0110](https://user-images.githubusercontent.com/72196604/235767048-792a6109-91c9-488f-bf84-859e43ac18c8.jpg)
//https://www.desiqna.in/7886/triology-codenation-coding-oa-sde-set-25-2022

```
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
int main() {
    
    ll n;
    cin>>n;
    ll a[n+1]={0};
    ll i = 1 ; 
    while(i<=n){
        cin>>a[i];
        i++;
    }
    
    ll b[40] = {0};
    unordered_map <ll,ll> kk ;
    kk[0]++;
    i = 1 ; 
    ll osi = 0 ; 
    while(i<=n){
        ll y = a[i];
        
        ll gg = 0 ; 
        //j--->row_number
        for(int j=30;j>=0;j--){
            int k = y >> j ;
            if(k&1){
                b[j]++;
            }
            
            if(b[j]%2!=0){
                ll vv = (1<<j);
                gg = (gg)^(vv);
            }
            
            
            
        }
        
        
        
        //cout<<gg;--->decimal conversion of current status....
        
        
        osi = osi + kk[gg] ; 
        
        
        kk[gg] = kk[gg] + 1 ;
        
        
        i++;
    }
    
    cout<<osi ; 
    
    
    return 0; 
    
}

