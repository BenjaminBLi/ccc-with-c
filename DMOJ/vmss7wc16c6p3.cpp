#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef vector<int> vi;

int N, M, cIdx, cRoot, cnt, dfn[100010], low[100010];
bool cut[100010], visited[100010];
vi adj[100010];

void tarjans(int u, int pre){
    //cout << u << endl;
    low[u] = dfn[u] = cIdx++;
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]) {
            if(cRoot == u) cnt++;
            tarjans(v, u);

            if(low[v] >= dfn[u]) cut[u] = true;

            low[u] = min(low[u], low[v]);
        }
        else if(v != pre)low[u] = min(low[u], dfn[v]);
    }
}

int main(){
    cIdx = 0;
    int tCnt = 0;
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        int u, v; scanf("%d %d", &u, &v);
        adj[u].pb(v); adj[v].pb(u);
    }
    for(int i = 1; i<=N; i++) if(!visited[i]){
        cnt = 0, cRoot = i;
        tarjans(i, -1);
        cut[i] = cnt > 1;
    }
    for(int i = 1;i <= N; i++) if(cut[i])tCnt++;
    printf("%d\n", tCnt);
    for(int i = 0; i <= N; i++) if(cut[i]) printf("%d\n", i);

    return 0;
}
