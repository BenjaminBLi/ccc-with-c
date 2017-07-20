#include "bits/stdc++.h"
using namespace std;

int n, m, adj[510][510], cnt;
bool visited[510];

void dfs(int u){
    visited[u] = true;
    for(int i=  1; i <= n; i++){
        if(visited[i]) continue;
        if(adj[u][i]) dfs(i);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    //cout << "DONE" << endl;
    int tot = 0;
    for(int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        dfs(i);
        for(int j = 1; j  <= n; j++){
            if(j == i) continue;
            if(visited[j]) tot++;
        }
    }
    printf("%d\n", tot);

    return 0;
}
