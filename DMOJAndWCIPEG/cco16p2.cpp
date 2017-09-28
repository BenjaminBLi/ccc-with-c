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

struct pt{
    double m;
    int x, y, w;
    pt(){};
    pt(int a, int b, int c){ x = a, y = b, w = c;}
    bool operator < (const pt &o) const{
        if(fabs(m-o.m) < 1e-9){
            if(x == o.x) return y < o.y;
            return x < o.x;
        }
        return m < o.m;
    }
} npts[4010], pts[4010];
struct spt{
    int wt = 0, wb = 0, w = 0, acnt = 0, bcnt = 0;
};

int n, yz, x0, bsum, fsum;
vector<spt> vpt;
spt c;

void inc(pt a){
    if(a.y > yz) {
        fsum += a.w;
        c.wt += a.w;
        c.acnt++;
    }
    else {
        bsum += a.w;
        c.wb += a.w;
        c.bcnt++;
    }
    c.w += a.w;
}

void getslope(int piv) {
    yz = npts[piv].y, x0 = npts[piv].x;
    vpt.clear();
    int cnt = 0;
    fori(i, 0, n) {
        if(i == piv) continue;
        pts[cnt] = npts[i];
        pts[cnt++].m = 1.0 * (npts[i].y - yz) / 1.0 * (npts[i].x - x0);
    }
    sort(pts, pts+cnt);
    bsum = fsum = 0;

    double mpre = pts[0].m;
    c.wb = c.wt = c.w = c.acnt = c.bcnt = 0;
    inc(pts[0]);
    fori(i, 1, cnt) {
        if (fabs(pts[i].m - mpre) < 1e-9) {
            inc(pts[i]);
        } else {
            vpt.pb(c);
            c.wb = c.wt = c.w = c.acnt = c.bcnt = 0;
            inc(pts[i]);
        }
        mpre = pts[i].m;
    }
    vpt.pb(c);
}

int main() {
    scanf("%d", &n);
    int sum = 0;
    fori(i, 0, n) {
        scanf("%d %d %d", &npts[i].x, &npts[i].y, &npts[i].w);
        sum += npts[i].w;
    }
    int ans = -40000000;
    fori(piv, 0, n) {
        getslope(piv);
        int w0 = npts[piv].w;
        int bst = 0;
        for (spt p : vpt) {
            fsum -= p.wt;
            fsum += p.wb;
            bst = max(bsum, fsum);
            printf("%d %d %d %d\n", bst, bsum, fsum, p.w);
            if (p.acnt == 0 || p.bcnt == 0) {
                ans = max(ans, max(bst, bst + max(p.w, p.w + w0)));
            } else {
                ans = max(ans, max(bst, bst + p.w + w0));
                ans = max(ans, bst + max(max(p.wb, p.wt), max(p.wb, p.wt) + w0));
            }
            bsum += p.wt;
            bsum -= p.wb;
        }
        cout << endl;
    }
    printf("%d\n", ans);
    return 0;
}
