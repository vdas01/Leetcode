//https://practice.geeksforgeeks.org/problems/subarrays-with-sum-k/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

```
   HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int sum=0;
        int ans=0;
        
        for(int i=0;i<N;i++){
            sum+=Arr[i];
             
            if(map.containsKey(sum-k)){
                
                ans+=map.get(sum-k);
            }
            if(map.containsKey(sum)){
                map.put(sum,map.get(sum)+1);
            }
            else{
                map.put(sum,1);
            }
        }
        return ans;

