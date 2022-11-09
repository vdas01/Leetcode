//https://leetcode.com/problems/online-stock-span/description/

class StockSpanner {
public:
stack<pair<int,int>>s;

    StockSpanner() {
        
    }
    
    int next(int price) {
      
       int sum = 1;
       while(!s.empty() && s.top().first <= price){
           sum+=s.top().second;
          s.pop();
       }
       s.push({price,sum});
       return sum;
    }
};

