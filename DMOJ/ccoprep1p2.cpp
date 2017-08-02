#include "bits/stdc++.h"
#define MAXN 410
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int N, low[MAXN], dfn[MAXN], cIdx = 0, cRoot, cnt, hi, stk[MAXN];
ull exits, ways;
vi adj[MAXN];
map<int, ii> id;
vector<set<int>> edgeSets;
vi vs;
bool vis[510], isArt[MAXN];

void markEs(int rE) {
    if (!stk[0]) return;
    cnt++;
    set<int> cv;
    while (true){
        int c = stk[stk[0]--];
        cv.insert(id[c].first);
        cv.insert(id[c].second);
        if (stk[0] == 0 || rE == c) break;
    }
    edgeSets.push_back(cv);
    vs.push_back(cv.size());
}

int findO(int u, ii e){
    if(e.first == u) return e.second;
    return e.first;
}

void dfs(int u) {
    low[u] = dfn[u] = ++cIdx;
    int fwdCnt = 0;
    for (int j : adj[u]) {
        int v = findO(u, id[j]);
        if(vis[j]) continue;
        stk[++stk[0]] = j;
        vis[j] = true;
        if (dfn[v] == 0) {
            fwdCnt++;
            dfs(v);
            if(low[u] > low[v]) low[u] = low[v];
            if (cRoot == u ? fwdCnt > 1 : low[v] >= dfn[u]) {
                isArt[u] = true;
                markEs(j);
            }
        } else if (low[u] > dfn[v]) low[u] = dfn[v];
    }
}

void root() {
    fori(i, 0, cnt){
        set<int> st = edgeSets[i];
        int aCnt = 0;
        for(int v : st) if(isArt[v]) aCnt++;
        if(aCnt > 1) continue;
        //cout << "YES" << endl;
        exits++;
        ways *= (ull) (vs[i]-aCnt);
    }
}

void reset(){
    id.clear();
    edgeSets.clear();
    vs.clear();

    fori(i, 0, 510){
        vis[i] = false;
    }
    fori(i, 0, MAXN){
        low[i] = dfn[i] = 0;
        isArt[i] = false;
        adj[i].clear();
    }
    stk[0] = 0;
    cnt = 0;
    hi = 0;
    exits = 0, ways = 1;
}

ull choose(ull N){
    return (ull) N * ((ull) N-1) /2;
}

int main(){
    scanf("%d", &N);
    while(N != 0){
        reset();
        fori(i, 0, N){
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(i);
            adj[v].push_back(i);
            id[i] = ii(u, v);
            hi = max(hi, max(u, v));
        }
        for(int i = 1; i <= hi; i++) if(dfn[i] == 0) {
                cRoot = i;
                dfs(i);
                if(stk[0]) markEs(-1);
            }
        root();
        if(exits == 1) exits = 2, ways = choose(ways);
        //fori(i, 0, hi) printf("%c, ", isArt[i] ? 'T' : 'F');
        printf("%lld %lld\n", exits, ways);
        scanf("%d", &N);
    }

    return 0;
}