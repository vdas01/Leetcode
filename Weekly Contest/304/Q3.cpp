//https://leetcode.com/contest/weekly-contest-304/problems/find-closest-node-to-given-two-nodes/
class Solution {
public:
    void path_maker(int node,int distance,vector<int>&edges,vector<int>&path){
        if(node != -1 && path[node] == -1){
            path[node] = distance;
            path_maker(edges[node],distance+1,edges,path);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
         int ans =-1;
        int minDist = INT_MAX;
        vector<int>path1(edges.size(),-1),path2(edges.size(),-1);
        path_maker(node1,0,edges,path1);
          path_maker(node2,0,edges,path2);
        for(int i=0;i<edges.size();i++){
            if(min(path1[i],path2[i]) >=0 && max(path1[i],path2[i]) < minDist){
                minDist = max(path1[i],path2[i]);
                ans = i;
            }
        }
        return ans;
    }
};