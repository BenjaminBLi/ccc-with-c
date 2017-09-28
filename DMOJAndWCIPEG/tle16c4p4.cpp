#include "bits/stdc++.h"
using namespace std;
typedef pair<int, long long> ii;
typedef vector<ii> vii;
typedef long long ll;

int N, M, Q, ansV, p[100010];
ll maxH;
bool visited[100010], totV[100010];
map<int, long long> adj[100010];

void dfs1(int u, ll cSz){
    //cout << u << endl;
    visited[u] = true;
    totV[u] = true;
    for(ii v : adj[u])
        if(!visited[v.first]) p[v.first] = u, dfs1(v.first, cSz + v.second);
    if(cSz > maxH){
        maxH = cSz;
        ansV = u;
    }if (cSz == maxH) ansV = u;
}

int main(){
    scanf("%d %d %d", &N, &M, &Q);
    if(Q == 1){
        for(int i = 0; i < M; i++){
            int u, v; ll w;
            scanf("%d %d %lld", &u, &v, &w);
            adj[u][v] = w;
            adj[v][u] = w;
        }
        ll tSz = 0;
        for(int i = 1; i <= N; i++){
            if(totV[i]) continue;
            ansV = i, maxH = 0;
            memset(visited, false, sizeof(visited));
            dfs1(i, 0);
            memset(visited, false, sizeof(visited));
            dfs1(ansV, 0);
            tSz += maxH+1;
        }
        printf("%lld\n", tSz-1);
    }else if(Q == 2){
        for(int i = 0; i < M; i++){
            int u, v; ll w;
            scanf("%d %d %lld", &u, &v, &w);
            adj[u][v] = w;
            adj[v][u] = w;
        }
        ll r1 = 0, r2 = 0;
        for(int i = 1 ;i <= N; i++){
            if(totV[i]) continue;
            ansV = i, maxH = 0;
            memset(visited, false, sizeof(visited));
            dfs1(i, 0);
            memset(visited, false, sizeof(visited));
            int e = ansV;
            dfs1(ansV, 0);
            ll bR = maxH, d = 0;
            p[e] = 0;
            for(int u = ansV; u && p[u] != 0; u = p[u]){
                bR = min(bR, max(d, maxH-d));
                d += adj[u][p[u]];
            }
            if(r1 < bR) r2 = r1, r1 = bR;
            else if(r2 < bR) r2 = bR;
        }
        //printf("%lld %lld\n", r1, r2);
        if(r1 != r2) printf("%lld\n", r1);
        else printf("%lld\n", r1+1);
    }

    return 0;
}
