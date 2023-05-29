//https://leetcode.com/discuss/interview-question/3549864/Google-or-sliding-window

You are standing at the top of the skyscrapper in NYC with camera, find the direction you should face to take the photo with most buildings

Input array sorted based on angles
2 inputs -> array with each entry representing 1 building at arr[i] degree
and field of view is given as 30 degree, so output the angle at which you will stand that maximum buildings are covered in 30 degree range

arr = [5, 9, 20, 22, 28, 35, 60, 350, 358, 359, 360]
field of view = 30

output : angle with maximum buildings

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
 
    ll gg = 0 ;
    ll d = 0 ; 
    while(i<=n && j<=n){
        if(i==j){
            d = b[j] - b[i] ; 
            if(d>k){
                i++;
                j++;
                if(i<=n){
                d = b[j] - b[i] ; 
                }
            }
            else{
                ll kk = 1 ;
                mv = max(kk,mv);
 
 
                j++;
 
                if(j<=n){
                d = b[j] - b[i];
                }
 
            }
        } else {
            d = b[j] - b[i] ;
            if(d>k){
                //[i....j] is invalid but [i......j-1] was valid
                //so->[i+1...j-1] will also be valid hence
                //i++ and j--
 
 
                i++;
                j--;
                if(i>j){
                    j = i ;
                }
 
                d = b[j] - b[i] ;
            }
            else {
                ll kk = abs(i-j) + 1 ;
 
                j++;
 
                if(j<=n){
                d = b[j] - b[i] ; 
                }
 
 
 
                mv = max(kk,mv);
            }
        }
    }
 
    cout<<mv ;
    return 0 ;
}
 
/*
5 3 
1 2 3 4 8 
*/

