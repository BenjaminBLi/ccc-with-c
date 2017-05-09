#include "bits/stdc++.h"
using namespace std;

int N, adj[1010][1010], visited[1010];
bool cycle;

void dfs(int u){
    //cout << u << endl;
    //for(int i = 0; i < N; i++) printf("%d, ", visited[i]); cout << endl << endl;
    visited[u] = 1;
    for(int i = 0;i < N; i++) if(adj[u][i]){
        //cout << "visiting: " << i << endl;
        if(visited[i] == 0){
            dfs(i);
        }else if(visited[i] == 1) {
            //cout << "entered here" << endl;
            cycle = true;
        }
    }
    visited[u] = 2;
}

int main(){
    scanf("%d", &N);
    memset(visited, 0, sizeof(visited));
    cycle = false;
    for(int i =0; i < N; i++) for(int j = 0;j < N; j++) scanf("%d", &adj[i][j]);
    for(int i = 0;i < N; i++) if(visited[i] == 0) dfs(i);

    if(!cycle) printf("YES\n");
    else printf("NO\n");

    return 0;
}
