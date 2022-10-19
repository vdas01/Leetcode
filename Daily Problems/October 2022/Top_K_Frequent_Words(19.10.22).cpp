//https://leetcode.com/problems/top-k-frequent-words/description/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<int,set<string>,greater<int>>m;
        map<string,int>m1;
        for(int i=0;i<words.size();i++)
        m1[words[i]]++;
        for (auto it:m1){
            // cout<<it.first<<" "<<it.second<<" "<<m1[it.first]<<" "<<"\n";
            m[it.second].insert(it.first);
        }
        vector<string>ans;
        int count=1;
        for(auto it:m){
            if(count<=k){
                for(auto it1 = m[it.first].begin();it1!= m[it.first].end();it1++){
                    ans.push_back(*it1);
                    if(ans.size()==k)
                    return ans;
                }
            }
        }
        return ans;
    }
};
