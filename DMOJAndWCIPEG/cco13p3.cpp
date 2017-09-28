#include "bits/stdc++.h"
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = en; i > st; i--)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int N;
ll ans, tCnt, len[400010], cnt[400010];
vi adj[400010];
bool visited[400010];

ll solve(int u){
    visited[u] = true;
    bool flag = true;
    for(int v : adj[u]){
        if(visited[v]) continue;
        flag = false;
        ll cLen = solve(v)+1;
        if(cLen + len[u] > ans){
            ans = cLen+len[u];
            tCnt = cnt[v]*cnt[u];
        }else if(cLen+len[u] == ans){
            tCnt += cnt[v]*cnt[u];
        }
        if(cLen > len[u]) len[u] = cLen, cnt[u] = cnt[v];
        else if(cLen == len[u]) cnt[u] += cnt[v];
    }

    if(flag) return 0;
    return len[u];
}

int main(){
    scanf("%d", &N);
    fori(i, 1, N) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0, tCnt = 0;
    fill(len+1, len+N+1, 0);
    fill(cnt+1, cnt+N+1, 1);
    solve(1);
    printf("%lld %lld", ans+1, tCnt);
    return 0;
}