#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

vi adj[100010];
ii edge[1000010];
int N, M, T, dfn[100010], low[100010], cId, stk[100010];
bool bridge[1000010], vis[1000010], valid[100010];

int getV(int id, int u){
    if(edge[id].first == u) return edge[id].s;
    return edge[id].f;
}

void dfs(int u, int pre){
    dfn[u] = low[u] = ++cId;
    stk[++stk[0]] = u;
    for(int e : adj[u]){
        int v = getV(e, u);
        if(v == pre) continue;
        vis[e] = true;
        if(dfn[v] == 0){
            dfs(v, u);
            if(low[u] > low[v]) low[u] = low[v];
            if(low[v] > dfn[u]){
                bridge[e] = true;
            }
        }else if(low[u] > dfn[v]) {
            for(int i = stk[0]; i && stk[i] != v; i--){
                cout << stk[i] << ", ";
            } cout << v << endl;
            low[u] = dfn[v];
        }
    }
    stk[0]--;
}

class g {
public:
    void solve(std::istream& in, std::ostream& out) {
        in >> T;
        T++;
        fori(t, 1, T) {
            stk[0] = 0;
            in >> N >> M;
            cId = 0;
            fori(i, 0, N) dfn[i] = low[i] = 0, valid[i] = true;
            fori(i, 0, M) {
                int u, v;
                bridge[i] = vis[i] = false;
                in >> u >> v;
                adj[u].pb(i);
                adj[v].pb(i);
                edge[i] = ii(u, v);
            }
            fori(i, 1, N + 1) {
                if (!dfn[i]) {
                    dfs(i, -1);
                }
            }
            fori(i, 1, N+1) cout << low[i] << ", "; cout << endl;
            cout << endl;
            int ans = 0;
            out << "Case #" << t << ": " << ans << "\n";
        }
    }
};
