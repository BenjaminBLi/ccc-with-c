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
ll cnt = 0;
map<int, int> dep;

int main(){
    scanf("%d", &n);
    for(int x; n--;){
        scanf("%d", &x);
        int d = 0;
        auto it = dep.lower_bound(x);
        if(it != dep.end()) d= max(d, it->s+1);
        if(it != dep.begin()) d = max(d, (--it)->s + 1);

        dep[x] = d;
        cnt += d;
        printf("%lld\n", cnt);
    }
    return 0;
}
