//https://www.codechef.com/problems/CATS/

```
[23:41, 8/28/2023] Vishal Das: int table[MAXBIT+1][N+1];
int calc(int c){
    int curr = jump[c];
    if(occupied[curr]) return 0;
    int count = 1;
    // while(true){
    //     int p = parent[curr];
    //     if(occupied[p]){
    //         break;
    //     }
    //     else{
    //         j++;
    //         curr = p;
    //     }
    // }
    for(int j=MAXBIT;j>=0;j--){
        int jp = table[j][curr];
        if(occupied[jp]){

        }
        else{
            curr = jp;
            count+= pow(2,j);
        }
    }
    occupied[p] = true;
    return j;
}

