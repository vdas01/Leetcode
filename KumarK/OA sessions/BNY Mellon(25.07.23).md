//https://www.desiqna.in/15202/bny-mellon-oa-july-2023-sde-team-formation

```
#include <bits/stdc++.h>
using namespace std;
int main()
{
 
    // vector<int> v={10,20,10,15,5,30,20};
    vector<int> v={17,12,10,2,7,2,11,20};
    // int k=3,team_size=2;
    int k=4,team_size=3;
 
    //logic
    priority_queue<int> f_pq;
    priority_queue<int> b_pq;
    int f=0,b=v.size()-1;
 
    //pushing k elements from start in f_pq
    for(int i=0;i<k;i++)
    {
        f_pq.push(v[i]);
        f++;
    }
 
    //pushing k element from end in b_pq
    while(k-- and f<=b)
    {
        b_pq.push(v[b]);
        b--;
    }
    b++; //adjustment factor due to indicies
 
 
    int ans=0;
    while(team_size--)
    {
        if(f_pq.top() and b_pq.top()){ //checking max out of b_pq and f_pq top
        ans+=max(f_pq.top(),b_pq.top());
        
              if(b_pq.top()>f_pq.top())
        {
            b_pq.pop();
 
            if(f<=b)
            {
                b_pq.push(v[b]);
                b--;
            }
 
        }
        else{
            f_pq.pop();
 
            if(f<=b)
            {
                f_pq.push(v[f]);
                f++;
            }
 
        }
            
        }
        else if(f_pq.top() and !b_pq.top())
        {
        ans+=f_pq.top();
        
        f_pq.pop();
 
            if(f<=b)
            {
                f_pq.push(v[f]);
                f++;
            }
 
        }
            
        
        else if(!f_pq.top() and b_pq.top())
        {
            ans+=b_pq.top();
            b_pq.pop();
 
            if(f<=b)
            {
                b_pq.push(v[b]);
                b--;
            }
 
        }
    }
        
     
    cout<<ans<<endl; 
 }
 
 
 
