//https://docs.google.com/document/d/12EwezVPCqLO51mNGvSA9qSR0sko1VWYcjeuK-PSURiQ/edit
```
#include <bits/stdc++.h>
using namespace std;
int result(vector<vector<int>>requests,int rate,int maxpackets){
    int n = requests.size();
    int total = 0,prev_time = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
        int time = requests[i][0], sent = requests[i][1];
        if(total != 0){
            total -= (time - prev_time)*rate;
        }
        total+= sent;
        prev_time = time;
        if(total > maxpackets){
            ans += abs(maxpackets - total);
            total -= abs(maxpackets-total);
        }
    }
    return ans;
}
int main() {
    vector<vector<int>>requests;
    int n,rate,maxpackets;
    cin>>n>>rate>>maxpackets;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        requests.push_back({a,b});
    }
    
    for(int i=0;i<n;i++){
        cout<<requests[i][0]<<" "<<requests[i][1]<<"\n";
    }
    cout<< result(requests,rate,maxpackets);
}
