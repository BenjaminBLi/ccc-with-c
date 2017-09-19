#include "bits/stdc++.h"
#define MAXN 20010
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, visited[MAXN+10], low[MAXN+10], dfn[MAXN+10], cIdx = 0, cRoot, cnt, m, stk[MAXN+10];
vi adj[MAXN+10];
vector<vi> groups;
vector<int> vs;
map<int, ii> id;
bool ok, vis[100010];

void markEs(int rE){
    if(!stk[0]) return;
    vi curr;
    set<int> cv;
    while(1){
        int c = stk[stk[0]--];
        curr.push_back(c);
        cv.insert(id[c].first);
        cv.insert(id[c].second);
        if(stk[0] == 0 || rE == c) break;
    }
    groups.push_back(curr);
    vs.push_back(cv.size());
}

int findO(int u, ii e){
    if(e.first == u) return e.second;
    return e.first;
}

void dfs(int u) {
    low[u] = dfn[u] = ++cIdx;
    for (int j : adj[u]) {
        int v = findO(u, id[j]);
        if(vis[j]) continue;
        stk[++stk[0]] = j;
        vis[j] = true;
        if (dfn[v] == 0) {
            dfs(v);
            if(low[u] > low[v]) {
                low[u] = low[v];
            }
            if (low[v] >= dfn[u]) {
                markEs(j);
            }

        } else if (low[u] > dfn[v]) {
            low[u] = dfn[v];
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    cIdx = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        ii e = ii(u, v);
        id[i] = e;
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    ok = true;
    for (int i = 1; i <= n; i++)
        if (dfn[i] == 0) {
            if(i != 1){
                printf("safe\n");
                return 0;
            }
            cRoot = i;
            dfs(i);
            if(stk[0]) markEs(-1);
        }

    long long ans = 1;
    for (int i = 0; i < (int) groups.size(); i++) {
        if(groups[i].size() == 1) continue;
        if (groups[i].size() != vs[i]) ok = false;
        if(!ok) break;
        //for(int e : groups[i]) printf("<%d, %d>, ", id[e].first, id[e].second); cout << endl;
        ans *= groups[i].size();
        ans %= (int) 1e9 + 7;
    }

    if (!ok) printf("safe\n");
    else printf("%lld\n", ans);
    return 0;
}
