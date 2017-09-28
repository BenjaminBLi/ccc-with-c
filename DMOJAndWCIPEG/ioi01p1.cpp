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

int S, ft[1030][1030], x, y, a, l, b, r, t;

void upd(int r, int c, int val) {
    for (; r <= S; r += (r & -r)) for (int nc = c; nc <= S; nc += (nc & -nc)) ft[r][nc] += val;
}
int val(int r, int c) {
    int ret = 0;
    for (; r; r -= r & -r) for (int nc = c; nc; nc -= nc & -nc) ret += ft[r][nc];
    return ret;
}
int val(int sr, int sc, int er, int ec){
    return val(er, ec) - val(sr-1, ec) - val(er, sc-1) + val(sr-1, sc-1);
}

int main(){
    int tmp;
    scanf("%d %d", &tmp, &S);
    int c;
    for(scanf("%d", &c); c != 3; scanf("%d", &c)){
        if(c == 1){
            scanf("%d %d %d", &x, &y, &a);
            upd(x+1, y+1, a);
        }else{
            scanf("%d %d %d %d", &l, &b, &r, &t);
            printf("%d\n", val(l+1, b+1, r+1, t+1));
        }
    }

    return 0;
}
