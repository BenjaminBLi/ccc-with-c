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
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int N, vals[100010];

double minv(int a) {
    if (a & 1) return 1.0 * a - 0.499999999;
    return 1.0 * a - 0.5;
}
double maxv(int a) {
    if (a & 1) return 1.0 * a + 0.499999999;
    return 1.0 * a + 0.5;
}
ll getval(double a) {
    auto p = (ll) a;
    double o = a - p;
    if (fabs(o - 0.5) < 1e-9) {
        return p + (p & 1 ? 1 : 0);
    } else if (o > 0.5) {
        return p + 1;
    } else {
        return p;
    }
}

int main(){
    scanf("%d", &N);
    double mina = 0, maxa = 0;
    int tmp;
    fori(i, 0, N){
        scanf("%d", &tmp);
        mina += minv(tmp);
        maxa += maxv(tmp);
    }

    printf("%lld\n%lld\n", getval(mina), getval(maxa));

    return 0;
}