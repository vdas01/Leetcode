//https://www.desiqna.in/15241/atlassian-sde-interview-coding-problem-2023

```
#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll ; 
 
int main() {
    ll n,k;
    n=8;
    k=5;
    ll i = 1 ; ll answer = -1e18;
    unordered_map <ll,ll> kk ; 
    ll sum = 0 ; 
    while(i<=n){
        ll yy ; cin>>yy;
        
        
        if(kk.find(yy)==kk.end()){
            kk[yy] = sum ; 
        } 
        
        if(kk.find(yy+k)!=kk.end()){
            ll gg = sum + yy - kk[yy+k] ; 
            answer = max(answer,gg);
            kk[yy] = min(kk[yy],sum);
           
        }
        
        if(kk.find(yy-k)!=kk.end()){
            ll gg = sum + yy - kk[yy-k] ; 
            answer = max(answer,gg);
            kk[yy] = min(kk[yy],sum);
        }
 
        
        
        sum = sum + yy ; 
 
 
        i++;
    }
    
    if(answer==-1e18){
        answer = 0 ; 
    }
    cout<<answer ; 
 
 
 return 0;
}
