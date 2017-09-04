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

int K, M;
char ch;

ll mod = 1000000007;
ll fpow(ll b, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e & 1) {
            e--;
            r *= b;
            r %= m;
        }
        e >>= 1;
        b *= b;
        b %= m;
    }
    return r % m;
}

int main() {
    scanf("%d %d", &K, &M);
    int cnt = 0;
    fori(i, 0, (1 << K)) {
        fori(j, 0, (1 << K)) {
            scanf(" %c", &ch);
            if (ch == '#') cnt++;
        }
    }
    cout << fpow(fpow(2, fpow(4, M, mod - 1), mod) - 1, cnt, mod) << "\n";
}
