Instead of priority_queue we will use ordered_set to store 
We can erase left over pairs so that we don't do extra traversal of that so bit optimized
```
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
	//from the source vertex S.
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
	    set<pair<int, int>> pq;

            vector<int> result(V, INT_MAX);

            result[S] = 0;
            pq.insert({0, S});

            while(!pq.empty()) {

                auto &it = *pq.begin();
                int d  = it.first;
                int node = it.second;
                pq.erase(it);

                for(auto &vec : adj[node]) {

                    int adjNode = vec[0];
                    int dist    = vec[1];

                    if(d + dist < result[adjNode]) {
                        
                        if(result[adjNode] != INT_MAX) {
                            auto iter = pq.find({result[adjNode], adjNode});
                            pq.erase(iter);
			    //OR, pq.erase({result[adjNode], adjNode});
                        }
                        
                        result[adjNode] = d + dist;
                        pq.insert({d+dist, adjNode});

                    }

                }

            }

            return result;
	}
  ```
