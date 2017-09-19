#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int N, p[100010], val[100010], a, sz[100010];
ii memo[100010];
char c1;
vi adj[100010];

int conv(string id){
    if(id == "?") return 1;
    if(id == "AC") return 0;
    return 2;
}

int getSz(int u){
    sz[u] = 1;
    for(int v : adj[u])
        sz[u] += getSz(v);
    return sz[u];
}

ii solve(int u) {
    ii ans1 = ii(0, 0), ans2 = ii(sz[u], sz[u]), tmp = ii(0, 0);
    for (int v : adj[u]) {
        tmp = solve(v);
        ans1.f += tmp.f, ans1.s += tmp.s;
        ans2.f -= tmp.s, ans2.s -= tmp.f;
    }

    if(val[u] == 0)
        return ans1;
    else if(val[u] == 2)
        return ans2;
    else
        return ii(min(ans1.f, ans2.f), max(ans1.s, ans2.s));
}

int main(){
    cin >> N;
    fori(i, 1, N+1){
        string id;
        memo[i] = ii(-1, -1);
        cin >> c1;
        if(c1 == 'C') {
            p[i] = -1;
            cin >> id;
        }else{
            cin >> a >> id;
            p[i] = a;
            adj[a].pb(i);
        }
        val[i] = conv(id);
    }
    ii ans = ii(0, 0), tmp;
    fori(i, 1, N+1){
        if(p[i] == -1){
            getSz(i);
            tmp = solve(i);
            ans.f += tmp.f, ans.s += tmp.s;
        }
    }
    printf("%d %d\n", ans.f, ans.s);

    return 0;
}
