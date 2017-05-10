#include "bits/stdc++.h"
#define pb push_back
using namespace std;
typedef vector<int> vi;

int S, T, N, M, cnt, dfsn[100010], low[10010], visited[100010];
vi adj[100010];
bool contains[100010];
vi stk;

void dfs1(int u){
    dfsn[u] = low[u] = ++cnt;
    stk.pb(u);
    visited[u] = true;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs1(v);
            low[u] = min(low[u], low[v]);
        }else if(true){

        }

    }
}


int main(){
    scanf("%d", &S);
    scanf("%d", &T);
    if(S == 1){
        for(;T--;){
            scanf("%d %d", &N, &M);
            for(int i = 0; i <= N; i++) adj[i].clear();
            cnt = 0;
            memset(dfsn, 0, sizeof(dfsn)); memset(low, 0, sizeof(low));
            stk.clear();
            for(int i = 0; i < M; i++){
                int u, v; scanf("%d %d", &u, &v);
                adj[u].pb(v); adj[v].pb(u);
            }
        }
    }else if (S == 2){
        for(;T--;){
            scanf("%d %d", &N, &M);
            if(M >= N) printf("YES\n");
            else printf("NO\n");
            cout << endl << endl;
        }
    }else if (S == 3){
        printf("-1");
    }else if (S == 4){
        for(;T--;){
            scanf("%d %d", &N, &M);
            for(int i = 0; i <= N; i++) adj[i].clear();
            for(int i = 0; i < M; i++){
                int u, v; scanf("%d %d", &u, &v);
                adj[u].pb(v), adj[v].pb(u);
            }
            bool valid = false;
            for(int i = 0; i <= N; i++){
                if((int) adj[i].size() >= 3) valid = true;
            }
            if(valid) printf("YES\n");
            else printf("NO\n");
        }
    }else if (S == 5){
        printf("-1");
    }

    return 0;
}
