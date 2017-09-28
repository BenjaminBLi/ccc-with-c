#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;

int M, N, cval[3001][3001], ft[3001][3001], r, c, r1, c1, r2, c2, v;

void upd(int r, int c, int v) {
    if ((r + c) & 1) v *= -1;
    int diff = v - cval[r][c];

    cval[r][c] = v;
    for (int nr = r; nr <= M; nr += nr & -nr)
        for (int nc = c; nc <= N; nc += nc & -nc)
            ft[nr][nc] += diff;
}

int rsq(int r, int c) {
    int ret = 0;
    for (int nr = r; nr; nr -= nr & -nr)
        for (int nc = c; nc; nc -= nc & -nc)
            ret += ft[nr][nc];
    return ret;
}
int rsq(int sr, int sc, int er, int ec){
    return rsq(er, ec) - rsq(er, sc-1) - rsq(sr-1, ec) + rsq(sr-1, sc-1);
}

int main() {
    scanf("%d %d", &M, &N);
    int c;
    for (scanf("%d", &c); c; scanf("%d", &c)) {
        if (c == 1) {
            scanf("%d %d %d", &r, &c, &v);
            upd(r, c, v);
        } else {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            int ans = rsq(r1, c1, r2, c2);
            if (((r1 + c1) & 1)) ans *= -1;
            printf("%d\n", ans);
        }
    }
    return 0;
}
