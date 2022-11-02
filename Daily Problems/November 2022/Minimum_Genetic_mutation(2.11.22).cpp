//https://leetcode.com/problems/minimum-genetic-mutation/description/
//my code :- wrong answer coming
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>visited;
        queue<string>q;
        q.push(start);
        visited.insert(start);
        char arr[] = {'A','C','G','T'};
        int count = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
            string rev = q.front();
            q.pop();
            if(rev == end)
            return count;
            for(char p : arr){
                for(int i=0;i<rev.size();i++){
                    string rnew = rev;
                    rnew[i] = p;
                    if(!visited.count(rnew) && find(bank.begin(),bank.end(),rnew) != bank.end()){
                        q.push(rnew);
                        visited.insert(rnew);
                    }
                }
            }
            count++;
          }
          
        }
        return -1;
    }
};
//
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int step = 1;
        deque<string>cur;
        deque<string>next;
        cur.push_back(start);
        while(!cur.empty()){
            string node = cur.front();
            cur.pop_front();
            for(auto& s: bank){
                if(s == "" || !isNeighbor(node, s)) continue;
                if(s == end) return step;
                next.push_back(s);
                s = "";
            }
            if(cur.empty()){
                step++;
                swap(cur, next);
            }
        }
        return -1;
    }
    
    bool isNeighbor(const string& a, const string& b){
        int diff = 0;
        for(int i = 0; i < a.size(); i++) if(a[i] != b[i] && ++diff > 1) return false;
        return diff == 1;
    }
};