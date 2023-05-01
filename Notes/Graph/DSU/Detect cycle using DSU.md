```
int find(int a){
     if(par[a]==a) return a;
      return par[a] = find(par[a]);
}

void Union(int a,int b){
  int p1 = find(a);
  int p2 = find(b);
  if(p1==p2) return;
  if(rank[p1]<rank[p2]){
       par[p1] = p2;
   }
    else{
       par[p2] = p1;
      if(rank[p1]==rank[p2]) rank[p1]++;
   }
}


bool detectCycle(int V,vector<int>adj[]){
parent.resize(v);
rank.resize(v);
for(int i=0;i<V;i++){
   parent[i] = i;
   rank[i] = 1;
}
   for(int u = 0; u<V ; u++){
      for(int &v: adj[u]){
          if(u < v){
             int parent_u = find(u);
             int parent_v = find(v);
              if(parent_u == parent_v)
              return true;
              
             Union(u,v);
          }
      }
   }
return false;
}
```
