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

int N, M, col[200010], sum;
ii curr;
vi adj[200010];
unordered_map<int, int> pairs;
bool ok, reach[201010];

class ufrisbee {
public:
    int dp() {
        reach[sum] = true;
        int best = 1<<30;
        for (ii p : pairs) {
            int stepSz = p.f, freq = p.s, len = stepSz * freq;
            fori(st, 0, stepSz) {
                int rCnt = 0, wSz = 0;
                bool seen = false;
                int en = st + len;
                for (int i = st+stepSz; wSz < freq; i += stepSz, wSz++)
                    if (reach[i]) rCnt++;

                for(int i = st; i <= sum; i += stepSz, en += stepSz){
                    if(rCnt) reach[i] = true;
                    if(i + stepSz <= sum && reach[i+stepSz]) rCnt--;
                    if(en <= sum && reach[en]) rCnt++;
                }
            }
        }

        int mid = sum>>1;

        fori(i, 0, sum+1) {
            if(reach[i] && abs(mid-i) < best) {
                best = abs(mid-i);
            }
        }
        return best;
    }

    void dfs(int u){
        if(col[u]) curr.first++;
        else curr.second++;
        for(int v : adj[u]){
            if(col[v] == col[u]) {
                ok = false;
            }
            if(col[v] == -1) {
                col[v] = 1 - col[u];
                dfs(v);
            }
        }
    }

    void solve(istream& in, ostream& out) {
        in >> N >> M;
        for(int i = 0; i <= N; i++) adj[i].clear(), reach[i] = false;
        pairs.clear();
        ok = true;
        sum = 0;
        for(int i = 0; i < M; i++){
            int u, v;
            in >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        memset(col, -1, sizeof(col));
        for(int i = 1; i <= N; i++) {
            if (col[i] == -1) {
                curr = ii(0, 0);
                col[i] = 0;
                dfs(i);
                pairs[abs(curr.first-curr.second)]++;
                sum += abs(curr.f-curr.s);
            }
        }

        if(!ok) {
            out << "Impossible\n";
        }else{
            int bDiff = dp();
            int a = N/2 - bDiff;
            int b = N/2 + bDiff;
            if(N&1) b++;
            out << a << " " << b << "\n";
        }
    }
};