//https://leetcode.com/problems/find-duplicate-file-in-system/
class Solution {
public:
    vector<string> spilt(string s)
{
    stringstream ss(s);
    string word;
        vector<string>ans;
    while (ss >> word) {
        // cout<<word<<" ";
        ans.push_back(word);
    }
        return ans;
}
    
vector<string> spilt2(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string>ans;
    while (!ss.eof()) {
        getline(ss, word, del);
        ans.push_back(word);
        // cout << word << endl;
    }
    return ans;
}
 
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>>m;
        vector<vector<string>>v;
        int n = paths.size();
        for(int i=0;i<n;i++){
            vector<string> s = spilt(paths[i]);
            for(int j = 1;j<s.size();j++){
                string p = s[j];
                // cout<<p<<"?";
               string content = p.substr(p.find('(')+1,p.find(')') -                                                             p.find('(') -1);
               
                string name = s[0] + '/' + p.substr(0,p.find('('));
                // cout<<content<<"---"<<name<<" ";
                 m[content].push_back(name);
             }
           
        }
     vector<vector<string>>result;
     for(auto it = m.begin();it != m.end();it++){
         if(it->second.size()>1){
             result.push_back(it->second);
         }
     }   
   return result;
    }
};