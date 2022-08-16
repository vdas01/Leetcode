class Solution {
public:
    int hasCycle(int sr,vector<vector<int>>&edges,vector<bool>&vis,set<int> &s){
        vis[sr] = true;
        s.insert(sr);
        for(int i=0;i<edges[sr].size();i++){
            if(s.find(edges[sr][i]) != s.end())
                return sr;
            if(!vis[edges[sr][i]]){
                int x = hasCycle(edges[sr][i],edges,vis,s);
                if(x!=-1)
                    return x;
            }
        }
        s.erase(sr);
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>>v(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1) v[edges[i]].push_back(i);
        }
        vector<bool>vis(edges.size(),false);
        int ans =-1;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
        set<int>s;
        int cycleNode = hasCycle(i,v,vis,s);
         if(cycleNode != -1){
             int sv = i;
             int c=1;
             while(edges[sv] != i){
                 sv = edges[sv];
                 c++;
             }
                 ans= max(ans,c);
         }
        }
         return ans;
    }
};