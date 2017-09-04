#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, sz;
ii pts[10010], piv;
vii stk;

int ccw(ii p1, ii p2, ii p3) {
    int a = (p2.f - p1.f) * (p3.s - p1.s) - (p2.s - p1.s) * (p3.f - p1.f);
    if (a > 0)
        return -1;
    else if (a < 0)
        return 1;
    return 0;
}

int sqDist(ii a, ii b){return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);}

bool comp(ii a, ii b){
    int o = ccw(piv, a, b);
    if(o == 0) return sqDist(piv, a) < sqDist(piv, b);
    return o == -1;
}

void scan() {
    if (n < 3) return;
    int ly = 0;
    fori(i, 1, n) {
        if (pts[i].s < pts[ly].s) ly = i;
        else if (pts[i].s == pts[ly].s && pts[i].f < pts[ly].f) ly = i;
    }
    if(ly != 0) swap(pts[0], pts[ly]);
    piv = pts[0];
    sort(pts + 1, pts + n, comp);
    fori(i, 0, 3) stk.pb(pts[i]);

    ii u;
    fori(i, 3, n){
        u = stk.back();
        stk.pop_back();
        while(ccw(stk.back(), u, pts[i]) != -1){
            u = stk.back();
            stk.pop_back();
        }
        stk.pb(u);
        stk.pb(pts[i]);
    }
}


int main() {
    scanf("%d", &n);
    fori(i, 0, n) scanf("%d %d", &pts[i].f, &pts[i].s);
    scan();
    stk.pb(stk[0]);
    int area = 0;
    int sz = stk.size();
    fori(i, 1, sz) {
        area += stk[i - 1].f * stk[i].s;
        area -= stk[i - 1].s * stk[i].f;
    }
    area = abs(area)/2;
    printf("%d\n", area/50);

    return 0;
}
