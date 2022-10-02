//https://leetcode.com/problems/longest-uploaded-prefix/description/
class LUPrefix {
public:
vector<int>v;
int prefix =-1;
    LUPrefix(int n) {
        v.resize(n);
        fill(v.begin(),v.end(),0);
    }
    
    void upload(int video) {
        v[video-1]++;  
    }
    
    int longest() {
            while(prefix+1 < v.size() && v[prefix+1])
            prefix++;
            return prefix+1;
    }
};
