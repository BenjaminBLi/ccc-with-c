#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <deque>
#include <cstring>
#include <sstream>
#define fori(i, st, en) for(int i = st; i < (int) (en); i++)
#define rfori(i, st, en) for(int i = st; i >= (int) (en); i--)
#define f first
#define s second
#define pb push_back
#define left(i) (i<<1)
#define right(i) (i<<1|1)
#define mid(l, r) ((l+r)>>1)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

const int MAXN = 100010;
int order[MAXN], a[MAXN], b[MAXN], z[MAXN], p[MAXN], n, sz[MAXN], val[MAXN];
ll curr = 0, ans[MAXN];
map<int, vi> tree[MAXN];

void us(int u, int v, int w) {
    if (sz[p[u]] < sz[p[v]]) swap(u, v);

    int pu = p[u];
    int pv = p[v];

    for (auto it : tree[pv]) {
        for (int x : it.s) {
            curr += tree[pu][val[u] ^ w ^ val[v] ^ val[x]].size();
        }
    }

    int prev = val[v];
    for(auto it : tree[pv]){
        for(auto x : it.s){
            val[x] = val[x] ^ prev ^ w ^ val[u];
            p[x] = pu;
            tree[pu][val[x]].pb(x);
        }
    }

    sz[pu] += sz[pv];
    tree[pv].clear();
    sz[pv] = 0;
}

int main(){
    curr = 0;
    scanf("%d", &n);
    fori(i, 0, n-1) {
        scanf("%d%d%d", a+i, b+i, z+i);
        a[i]--, b[i]--;
    }

    fori(i, 0, n-1){
        scanf("%d", order + i);
        order[i]--;
    }

    fori(i, 0, n){
        tree[i][0].pb(i);
        sz[i] = 1;
        p[i] = i;
    }


    rfori(i, n-2, 0){
        us(a[order[i]], b[order[i]], z[order[i]]);
        ans[i] = curr;
    }

    ans[n-1] = 0;
    fori(i, 0, n){
        printf("%lld\n", ans[i]);
    }
    return 0;
}

