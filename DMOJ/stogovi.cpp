#include <bits/stdc++.h>
#define ll (long long)
using namespace std;
const int D = 19;
int N, table[D][300002], u, w, t, dep[300002], val[300002]; char ch;
//val represents the direct ancestor of stack i
//operation a is add a brtableh down to the current node
//b is just go back to node n
//c is to find the lca of the branch: Find the difference between the depths of u and the lca
//T[k][u] = T[k-1][T[k-1][u]] <- takes logn levels

int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int i = D-1; i >= 0; i--)
        if(dep[x] >= dep[y] + (1<<i)) x = table[i][x];
    if (x == y) return y;
    for(int i = D-1; i >= 0; i--) //sparse table of LCA is divided by 2^i
        if(table[i][x] != -1 && table[i][x] != table[i][y])
            x = table[i][x], y = table[i][y];
    return table[0][x];
}


int main(){
    memset(table, -1, sizeof(table));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf(" %c %d", &ch, &u);
        if(ch == 'a'){
            val[i] = i;
            t = val[u];
            dep[i] = dep[t]+1; table[0][i]=t;
            for(int j = 1; j < D; j++){
                if(table[j-1][i] != -1)
                    table[j][i] = table[j-1][table[j-1][i]];
                else break;
            }
        }else if (ch == 'b'){
            printf("%d\n", val[u]);
            val[i] = table[0][val[u]];
        }else{
            scanf(" %d", &w);
            val[i] = val[u];
            t = lca(val[u], val[w]);
            printf("%d\n", dep[t]);
        }
    }
    return 0;
}
