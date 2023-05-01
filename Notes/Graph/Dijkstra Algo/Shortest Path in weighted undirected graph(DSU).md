Q) Tell shortest path from node 1 to node 3:-
Why not bfs bcoz bfs will not work in weighted graph where weight of each edge is not equal


```
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            int w = vec[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> result(n+1, INT_MAX);
        vector<int> parent(n+1);
        
        for(int i = 1; i<=n; i++) {
            parent[i] = i;
        }
        
        result[1] = 0;
		pq.push({0, 1});

		while(!pq.empty()) {

		    int d  = pq.top().first;
		    int node = pq.top().second;
		    pq.pop();

		    for(auto &it : adj[node]) {

    			int adjNode = it.first;
    			int dist    = it.second;
    
    			if(d + dist < result[adjNode]) {
    
    			    result[adjNode] = d + dist;
    			    pq.push({d+dist, adjNode});
    			    parent[adjNode] = node;
    
    			}

		    }

		}

        vector<int> path;
        int node = n;
        
        if(result[node] == INT_MAX)
            return {-1};
        
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1); //source
        reverse(begin(path), end(path));
		return path;
    }
};
