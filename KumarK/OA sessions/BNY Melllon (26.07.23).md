//https://docs.google.com/document/d/1tn-dP1ZznNLLghvsYPEQMwKO_uv15qG3Fs5toOdnpq4/edit

```
#include <iostream>
using namespace std;
class solution{
public:
    void max_upgrade(int *num_server, int *money, int *upgrade, int *sell, int n){
        for (int i = 0; i<n; i++){
            int l=0, r=num_server[i];
            while(l<=r){
                int upgraded = l + (r-l)/2;
                int sold = num_server[i] - upgraded;
                if (upgraded*upgrade[i] <= money[i] + sell[i]*sold){
                    l=upgraded+1;
                }else{
                    r=upgraded-1;
                }
            }
            cout<<r<<' ';
        }
        cout<<'\n';
    }
};
int main()
{
    int n;cin>>n;
    int num_server[n], money[n], upgrade[n], sell[n];
    for (int i=0;i<n;i++)
        cin>>num_server[i]>>money[i]>>sell[i]>>upgrade[i];
    solution ans;
    ans.max_upgrade(num_server, money, upgrade, sell, n);
    return 0;
}
