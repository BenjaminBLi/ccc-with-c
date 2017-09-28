#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

struct e{
    int u, v, w;
    e(){}
    e(int a, int b, int c){u = a, v = b, w = c;}
    bool operator < (const e& o)const{
        return w < o.w;
    }
    bool operator > (const e& o) const{
        return w > o.w;
    }
};

int N, memo[2010], tmp[2010], dist[2010];
ii coords[2010];

vector<e> es;

int sDist(ii a, ii b){
    return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
}
bool comp(e a, e b){
    return a < b;
}

int main() {
    scanf("%d", &N);
    fori(i, 0, N) scanf("%d %d", &coords[i].f, &coords[i].s);

    fori(i, 0, N) fori(j, i+1, N) {
            es.pb(e(i, j, sDist(coords[i], coords[j])));
        }
    fori(i, 0, N) es.pb(e(N, i, sDist(coords[i], ii(0, 0))));
    sort(es.begin(), es.end(), comp);
    int sz = es.size();
    fori(i, 0, sz){
        e c = es[i];
        if(c.w > dist[c.u]) dist[c.u] = c.w, tmp[c.u] = memo[c.u];
        if(c.w > dist[c.v]) dist[c.v] = c.w, tmp[c.v] = memo[c.v];
        if(c.u == N) memo[N] = max(memo[N], tmp[c.v]+1);
        else{
            memo[c.u] = max(memo[c.u], tmp[c.v]+1);
            memo[c.v] = max(memo[c.v], tmp[c.u]+1);
        }
    }
    printf("%d\n", memo[N]);

    return 0;
}
