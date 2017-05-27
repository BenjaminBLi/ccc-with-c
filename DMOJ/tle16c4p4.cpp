#include "bits/stdc++.h"
using namespace std;
typedef pair<int, long long> ii;
typedef vector<ii> vii;
typedef long long ll;

int N, M, Q, ansV;
ll maxH, longest[100010], secLong[100010];
bool visited[100010], totV[100010];
vii adj[100010];

void dfs1(int u, ll cSz){
    visited[u] = true;
    totV[u] = true;
    //printf("%d: %lld\n", u, cSz);
    for(ii v : adj[u])
        if(!visited[v.first]) dfs1(v.first, cSz + v.second);
    if(cSz > maxH){
        maxH = cSz;
        ansV = u;
        len[u] = max(len[u], maxH);
    }
}

void dfs2(int u){

}

int main(){
    scanf("%d %d %d", &N, &M, &Q);
    if(Q == 1){
        for(int i = 0; i < M; i++){
            int u, v; ll w;
            scanf("%d %d %lld", &u, &v, &w);
            adj[u].push_back(ii(v, w));
            adj[v].push_back(ii(u, w));
        }
        ll tSz = 0;
        for(int i = 1; i <= N; i++){
            if(totV[i]) continue;
            ansV = -1, maxH = 0;
            memset(visited, false, sizeof(visited));
            dfs1(i, 0);
            memset(visited, false, sizeof(visited));
            dfs1(ansV, 0);
            tSz += maxH+1;
        }
        printf("%lld\n", tSz-1);
    }else if(Q == 2){
        if(M == 1){
            int u, v;ll w;
            scanf("%d %d %lld", &u, &v, &w);
            printf("%lld\n", w);
        }else{
            for(int i = 1 ;i <= N; i++){
                if(totV[i]) continue;

            }
        }

    }

    return 0;
}
