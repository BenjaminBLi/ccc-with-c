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

int n;

int main(){
    scanf("%d", &n);

    ll sm = 0, mx = 1, x;
    for(int i = 0; i < n; i++){
        scanf("%lld", &x);
        sm += x;
        mx = max(mx, x);
    }

    cout << min(sm-mx, sm/2) << endl;

    return 0;
}

