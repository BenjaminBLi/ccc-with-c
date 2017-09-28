#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int N, M, K;
bitset<1510> adj[1510], tmp, last[1510], res[1510];

void selfMultiply(){
    for(int i = 1; i <= N; i++){
        last[i] = res[i];
        res[i].reset();
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1;j <= N; j++){
            tmp.reset();
            tmp |= last[i]&adj[j];
            res[i][j] = tmp.any();
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i =0;i < M; i++){
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = true; adj[v][u] = true;
        res[u][v] = true; res[v][u] = true;
    }
    for(int i= 0; i <= N; i++) adj[i][i] = true, res[i][i] = true;
    //for(int k = 1; k <= N; k++){ for(int j = 1; j <= N; j++) printf("%d ", res[k][j] ? 1 : 0);printf("\n"); }printf("\n");

    for(int i = 1; i < K; i++) {
        selfMultiply();
        //for(int k = 1; k <= N; k++){ for(int j = 1; j <= N; j++) printf("%d ", res[k][j] ? 1 : 0);printf("\n"); }printf("\n");
    }
    for(int i = 1; i <= N; i++){
        printf("%d\n", (int)res[i].count());
    }


    return 0;
}