//Longest K unique characters substring

```
int longestKSubstr(string s, int k) {

    // your code here

    map<char,int>m;

    int ans=-1,j=0;

    for(int i=0;i<s.size();i++){

        m[s[i]]++;

        if(m.size()==k){

            ans=max(ans,i-j+1);

        }

        while(m.size()>k&& j<s.size()){

            m[s[j]]--;

            if(m[s[j]]==0){

                m.erase(s[j]);

            }

            j++;

        }

    }

    return ans;

    }
