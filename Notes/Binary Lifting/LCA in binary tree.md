//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

```
int lca(int u,int v){
    //assume level[v] > level[u]

    while(level[u] != level[v]){
        v = parent[v];
    }
    if(u == v)
    return u;
    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int lca(int u,int v){
    //assume level[v] > level[u]
    int k = level[v] - level[u];
   for(int i=MAXBIT; i>=0;i--){
       int mask = 1 << i;
       if(k & mask){
           v = table[i][v];
       }
   }
    if(u == v)
    return u;
   for(int i=MAXBIT;i>=0;i--){
       int up = table[i][u];
       int vp = table[i][v];
       if(up != vp){
           u = up;
           v = vp;
       }
   }
    u = parent[u];
    return u;
}
