#include <bits/stdc++.h>
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

const int MAXN = 10010;
int n, m, dist[MAXN], st, en;
vii adj[MAXN];

//1 is uphill, 0 is downhill. though that doesn't really matter.
int solve(int flag){
    memset(dist, 0x3f, sizeof dist);
    dist[st] = 0;
    deque<ii> q;
    q.push_back({st, flag});
    while(q.size()){
        int u = q.front().f, p = q.front().s;
        q.pop_front();
        for(ii e : adj[u]){
            if(dist[e.f] > dist[u] + abs(p - e.s)){
                dist[e.f] = dist[u] + abs(p - e.s);
                if(p == e.s) q.push_front(e);
                else q.push_back(e);
            }
        }
    }

    return dist[en];
}

int main(){
    scanf("%d%d", &n, &m);
    fori(i, 0, m){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(ii(v, 1));
        adj[v].pb(ii(u, 0));
    }
    scanf("%d%d", &st, &en);

    cout << min(solve(0), solve(1)) << endl;

    return 0;
}

