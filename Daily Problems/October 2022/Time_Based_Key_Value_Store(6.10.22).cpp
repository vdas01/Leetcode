//https://leetcode.com/problems/time-based-key-value-store/
class TimeMap {
public:
unordered_map<string,vector<pair<string,int>>>m;
string search(vector<pair<string,int>>arr, int timestamp){
    int l = 0,h = arr.size()-1;
     string res = "";
     while(l<=h){
         int mid = l+(h-l)/2;
         if(arr[mid].second == timestamp)
         return arr[mid].first;
         else if (arr[mid].second < timestamp){
             res = arr[mid].first;
             l = mid+1; 
         }
         else{
             h = mid-1;
         }
     }
   return res;
}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
        return search(m[key],timestamp);
    }
};
