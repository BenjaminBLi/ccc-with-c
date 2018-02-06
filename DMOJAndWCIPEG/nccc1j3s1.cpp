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

double k, p, x;

inline double f(double m){
    return m*x + k*p/m;
}

int main(){
    cin >> k >> p >> x;
    double mag = sqrt(k*p/x);
    double a = floor(mag);
    double b = ceil(mag);

    double ans = min(f(a), f(b));

    printf("%.3lf\n", ans);
    return 0;
}

