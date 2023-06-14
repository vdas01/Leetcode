

```
class DataStream {
    int sum,t;
   int count = 0;
    queue<int>q;
public:
    DataStream(int value, int k) {
        sum = value;
        t = k;
    }
    
    bool consec(int num) {
        q.push(num);
        if(num == sum)
        count++;
       
        while(q.size() > t){
            if(q.front() == sum)
             count--;
            q.pop();
        }
        
        if(q.size() == t && count == t)
        return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
