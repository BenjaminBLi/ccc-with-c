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

int N, Q, x, y, z, xa, x2, ya, y2, za, z2;
ll  cval[251][251][251], ft[251][251][251], l;
char ch;

void upd(int x, int y, int z, ll nv){

    ll val = nv - cval[x][y][z];
    cval[x][y][z] = nv;
    for(int nx = x; nx <= N; nx += (nx & -nx))
        for(int ny = y; ny <= N; ny += (ny & -ny))
            for(int nz = z; nz <= N; nz += (nz & -nz))
                ft[nx][ny][nz] += val;
}
ll rsq(int x, int y, int z){
    ll ret = 0;
    for(int nx = x; nx; nx -= (nx & -nx))
        for(int ny = y; ny; ny -= (ny & - ny))
            for(int nz = z; nz; nz -= (nz & -nz))
                ret += ft[nx][ny][nz];
    return ret;
}
ll rsq(int xa, int ya, int z1, int x2, int y2, int z2){
    return rsq(x2, y2, z2) - rsq(x2, y2, z1-1) - rsq(x2, ya-1, z2) - rsq(xa-1, y2, z2) + rsq(xa-1, ya-1, z2) + rsq(xa-1, y2, z1-1) + rsq(x2, ya-1, z1-1) - rsq(xa-1, ya-1, z1-1);
}

int main(){
    scanf("%d %d", &N, &Q);
    ll ans = 0;
    fori(q, 0, Q){
        scanf(" %c", &ch);
        if(ch == 'C') {
            scanf("%d %d %d %lld", &x, &y, &z, &l);
            upd(x, y, z, l);
        }else{
            scanf("%d %d %d %d %d %d", &xa, &ya, &za, &x2, &y2, &z2);
            ans +=  rsq(xa, ya, za, x2, y2, z2);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
