#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int N, M, cIdx, low[100010], dfn[100010], cRoot, cnt;

map<int, int> adj[100010], bridge[100010];
ll memo[100010];
bool visited[100010], isArti[100010];

void tarjans(int u, int pre){
    low[u] = dfn[u] = cIdx++;
    visited[u] = true;
    for(ii v : adj[u]){
        if(v.first == pre) continue;
        if(!visited[v.first]){
            if(cRoot == v.first) cnt++;
            tarjans(v.first, u);
            if(low[v.first] >= low[u]) isArti[u] = true;
            low[u] = min(low[u], low[v.first]);
            if(low[v.first] > dfn[u]) bridge[u][v.first] = 1, bridge[v.first][u] = 1;
        }else{
            low[u] = min(low[u], dfn[v.first]);
        }
    }
}


int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w;
    }
    memset(memo, -1, sizeof(memo));
    cRoot = 1, cnt = 0;
    tarjans(1, -1);
    memset(visited, false, sizeof(visited));

    return 0;
}
