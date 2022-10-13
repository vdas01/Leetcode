//https://leetcode.com/contest/weekly-contest-314/problems/the-employee-that-worked-on-the-longest-task/

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int time = 0,mtime =INT_MIN, mid = -1;
        for(int i=0;i<logs.size();i++){
            int first = logs[i][0],second = logs[i][1];
            cout<<first<<" "<<second<<" "<<time<<" "<<mtime<<" "<<mid<<"\n";
            if((second-time) > mtime){
                mtime = second - time;
                mid = first;
               
            }
            else if((second-time) == mtime && mid > first){
                mid = first;
            }
             time = second;
        }
        return mid;
    }
};