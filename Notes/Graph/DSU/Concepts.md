Dsu is different components.
Initially everyone is its own parent.
Two operations:- 
1)Union :- Combine two given sets .e.g(a,b)
Steps:-
Find parent of both sets and if both have diff. parent then do union then both sets will come in one set.
Let say set a becomes parent of b

2)Union Find:- Tell if two members belong to same set
find(c):- tells the ultimate parent of node c
find(d):- tells the ultimate parent of node d
if both have same parent then they belong to same set

```
int find(int i,vector<int> &parent){
  if(i == parent[i])
  return i;
   return find(parent[i]);
}


void Union(int x,int y,vector<int> &parent){
   int px = find(x,parent),py = find(y,parent);
    if(px != py){
      parent[px] = py;
   }
}
```
But here doing union like this will increase the length of set which will result in nearly o(n) in union find or find of parent.

To optimize we can do path compression:- 
```
int find(int i,vector<int> &parent){
  if(i == parent[i])
  return i;
   return parent[i]  = find(parent[i]);
}
```

More optimise using rank in Union.
Steps:-
1)maintain another vector of rank. Initally rank has 0 of everyone.
2) if two sets have same rank say a and b and we are merging b with a then we will increase rank of a
  if rank of a > rank of b then parent[b] = a; 
3) When we find rank then we find rank of their ultimate rank

```
void Union(int x,int y,vector<int> &parent){
   int px = find(x,parent),py = find(y,parent);
    if(px == py)
         return;
         
     if(rank[px] > rank[py])
       parent[py] = px;
     else if(rank[py] > rank[px])
        parent[px] = py;
     else{
         parent[px] = py;
          rank[py]++;
     }
}
```

```
class DSU {
    private:
        vector<int> parent;
        vector<int> rank;


    public : 
        
        DSU(int n) {
            parent.resize(n+1);
            rank.resize(n+1);
           
            for(int i = 1; i<=n; i++) {
                parent[i] = i;
            }
        }
    
        int find (int x) {
            if (x == parent[x]) 
                return x;

            return parent[x] = find(parent[x]);
        }

        void Union (int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
         
        }
    
};
```




