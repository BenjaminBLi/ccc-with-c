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

int N, M, dst[2][3010], dist[2][3010];
ii pts[2][3010];
bool vis[2][3010], spt[2][3010], adj[2][3010][3010];

int sqd(ii a, ii b) {
    return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}

bool ok(int id, int a, int b) {
    return sqd(pts[id][a], pts[id][b]) <= dst[id][a] * dst[id][a];
}

int mindst(int id, int sz){
    int sm = 1<<30, sidx;
    fori(i, 0, sz){
        if(!spt[id][i] && dist[id][i] <= sm){
            sm = dist[id][i];
            sidx = i;
        }
    }
    return sidx;
}

void solve(int id, int sz, int st) {
    fori(i, 0, sz) {
        dist[id][i] = 3001;
        spt[id][i] = false;
    }
    dist[id][st] = 0;
    fori(cnt, 1, sz) {
        int u = mindst(id, sz);
        spt[id][u] = true;
        fori(i, 0, sz) {
            if (!spt[id][i] && adj[id][u][i] && dist[id][u] + 1 < dist[id][i]) {
                dist[id][i] = dist[id][u] + 1;
            }
        }
    }
}

void buildG(int id, int sz){
    fori(i, 0, sz){
        fori(j, i+1, sz){
            if(ok(id, i, j)) adj[id][i][j] = true;
            if(ok(id, j, i)) adj[id][j][i] = true;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    int my = 0, stid1 = 0, en1 = 0;
    fori(i, 0, N) {
        scanf("%d %d %d", &pts[0][i].f, &pts[0][i].s, &dst[0][i]);
        if(pts[0][i].s > my){
            my = pts[0][i].s;
            stid1 = i;
        }
        if(dst[0][i] == 9001) en1 = i;
    }
    my = 0;
    int stid2 = 0, en2 = 0;
    fori(i, 0, M) {
        scanf("%d %d %d", &pts[1][i].f, &pts[1][i].s, &dst[1][i]);
        if(pts[1][i].s > my){
            my = pts[1][i].s;
            stid2 = i;
        }
        if(dst[1][i] == 9001) en2 = i;
    }
    buildG(0, N);
    buildG(1, M);

    //cout << stid1 << endl;
    solve(0, N, stid1);
    solve(1, M, stid2);
   // fori(i, 0, N) cout << dist[0][i] << ", "; cout << endl;
   // cout << dist[0][en1] << endl;

    if(dist[0][en1] == dist[1][en2]) printf("SUDDEN DEATH");
    else if(dist[0][en1] < dist[1][en2]) printf("We are the champions!");
    else printf(":'(");

    return 0;
}
