```
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
 
int main() {
    ll n ;
    cin>>n ;
    ll k ;
    cin>>k ;
    ll b[n+1] = {0};
    ll i = 1 ;
    while(i<=n){
        cin>>b[i];
        i++;
    }
 
    i = 1 ;
    ll j = 1 ;
    ll mv = 0 ;
    ll c = 0 ; 
    ll gg = 0 ;
    ll sum = b[1] ;
    while(i<=n && j<=n){
        if(i==j){
            if(b[i]>k){
                i++;
                j++;
                if(i<=n){
                sum = b[i] ;
                }
            }
            else{
                ll kk = 1 ;
                mv = max(kk,mv);
               
                j++;
                if(j<=n){
                sum = sum + b[j] ;
                }
            }
        } else {
            if(sum>k){
                //[i....j] is invalid but [i......j-1] was valid
                
                cout<<i<<" "<<j-1<<"\n";
                ll w1 = i ; 
                ll w3 = j-1 ;  
                ll l = abs(w1-w3) + 1 ;
                c = c + l ; 
                sum = sum - b[i] ;
                i++;
                sum = sum - b[j] ;
                j--;
                if(i>j){
                    j = i ;
                }
            }
            else {
                ll kk = abs(i-j) + 1 ;
             
                j++;
 
                if(j<=n){
                sum = sum + b[j] ;
                }
 
                if(j==n+1){
 
                    gg = i ;
                }
 
                mv = max(kk,mv);
            }
        }
    }
    cout<<gg ; cout<<'\n';
    
    if(gg>=1){
        ll w1 = gg ; 
        ll w3 = n ;  
        ll l = abs(w1-w3) + 1 ;
        c = c + (l*(l+1))/2;
    }
    
    
    //cout<<mv ;
    cout<<c ; 
    return 0 ;
}
 
