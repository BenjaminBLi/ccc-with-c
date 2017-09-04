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

int T, N, B, memo[6][3010];
vii sh[6];


int main() {
    scanf("%d %d", &T, &N);
    fori(i, 0, N) {
        int c, v, t;
        scanf("%d %d %d", &c, &v, &t);
        sh[t].pb(ii(c, v));
    }
    scanf("%d", &B);
    memset(memo, -1, sizeof(memo));
    fori(i, 0, T + 1) memo[i][0] = 0;
    fori(i, 0, B + 1) memo[0][i] = 0;
    fori(t, 1, T + 1) {
        int sz = sh[t].size();
        fori(i, 0, sz) {
            ii c = sh[t][i];
            fori(j, c.f, B + 1) {
                if (memo[t - 1][j - c.f] != -1) {
                    memo[t][j] = max(memo[t][j], max(memo[t][j - 1], c.s + memo[t - 1][j - c.f]));
                }
            }
        }
    }

    cout << memo[T][B] << endl;

    return 0;
}