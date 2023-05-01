Helps to find shortest path from source to all other edges in Unidirected Weighted Graph
Steps:- 
1) First take a dist vector with all distances from sources initliazed to 0;
2)Make a min heap of pair<int,int>
3)Make dist[source] = 0 and put in heap {0,source};
4) take source = heap.top().second , dist = heap.top().first;
5) Iterate over the negibours of source 
6) Now see the dist of neighbour and if(dist[nieghbour] > dist + adj[source][i][0]) then update dist of neighbour and push in heap {dist[neighbour],neighbour} and do bfs
7)repeat the above steps

```
vector<int>dijkstra(int S,int n,vector<vector<int>>adj[]){
  //TC:- o(E * log(V))
    vector<int>dist(n,INT_MAX);
    priority_queue<int,vector<int>,greater<int>>pq;
    dist[S] = 0;
    pq.push({0,S});
    while(!pq.empty()){
        int initial_dist = pq.top().first,node = pq.top().second;
        for(auto &vec : adj[node]){
            int curr_dist = vec[1] , curr_node = vec[0];
            if(dist[curr_node] > curr_dist + initial_dist){
                dist[curr_node] = curr_dist + initial_dist;
                pq.push({curr_dist + initial_dist,curr_node});
            }
        }
    }
  return dist;
}
```
