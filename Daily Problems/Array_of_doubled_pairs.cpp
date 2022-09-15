//https://leetcode.com/problems/array-of-doubled-pairs/submissions/
class Solution {
public:
    bool static comp(int &i,int &j){
        if(i<0 && j<0)
            return i > j;
        else 
            return i < j;
    }
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end(),comp);
        int n = arr.size();
       map<int,int>m;
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
            m[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(m[arr[i]] > 0){
            m[arr[i]]--;
            if(m[2*arr[i]] == 0) return false;
            m[2*arr[i]]--;
            }
        }
        return true;
    }
};