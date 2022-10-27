//https://leetcode.com/problems/image-overlap/description/

class Solution {
public:
  
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>>v1,v2;
        for(int i=0;i<n;i++){
            for(int j=0;j<img1[i].size();j++){
                if(img1[i][j] == 1)
                v1.push_back({i,j});
                if(img2[i][j] == 1)
                v2.push_back({i,j});
            }
        }
        map<pair<int,int>,int>m;
        int ans = 0;
        for(auto it:v1){
            for(auto it1:v2){
               m[{it1.first - it.first,it1.second - it.second}]++;
               ans = max(ans,m[{it1.first - it.first,it1.second - it.second}]);
            }
        }
        return ans;
    }
};