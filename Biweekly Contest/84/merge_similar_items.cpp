//https://leetcode.com/contest/biweekly-contest-84/problems/merge-similar-items/
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>>ans;
        map<int,int>m;
        for(int i=0;i<items2.size();i++){
            m.insert({items2[i][0],items2[i][1]});
        }
        for(int i=0;i<items1.size();i++){
            if(m.find(items1[i][0])!= m.end()){
            ans.push_back({items1[i][0],items1[i][1]+m[items1[i][0]]});
            m.erase(items1[i][0]);
            }
            else{
                 ans.push_back({items1[i][0],items1[i][1]});
            }
        }
        for(auto it : m){
            ans.push_back({it.first,it.second});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};