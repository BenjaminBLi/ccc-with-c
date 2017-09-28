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

int n, S, m[20], memo[1<<11][20];
vii msk[1<<11];

void gen(int idx, int mask, int c){
    if(idx == n) {
        if (__builtin_popcount(c) & 1) {
            int o = mask & (~c);
            msk[mask].pb(ii(o, c));
        }
        return;
    }
    if(mask & (1<<idx))
        gen(idx+1, mask, c | (1<<idx));
    gen(idx+1, mask, c);
}

int solve(int mask, int rem) {
    if(memo[mask][rem] != -1) return memo[mask][rem];
    int &bst = memo[mask][rem] = 0;
    fori(i, 0, n) {
        if ((mask & (1 << i)) == 0) continue;
        mask ^= (1 << i);
        if (mask == 0) {
            bst = max(bst, (m[i] + rem) * (m[i] + rem) + rem);
            break;
        }
        for (ii p : msk[mask]) {
            fori(p1, 0, rem + 1) {
                fori(p2, 0, rem + 1 - p1) {
                    int in = rem - p1 - p2;
                    int with = solve(p.f, p1) * solve(p.s, p2);
                    int only = (m[i] + in) * (m[i] + in);
                    bst = max(bst, min(only, with) + in);
                }
            }
        }
        mask ^= (1 << i);
    }
    return bst;
}


int main(){
    memset(memo, -1, sizeof(memo));
    scanf("%d %d", &n, &S);
    fori(i, 0, n) scanf("%d", m+i);
    fori(i, 0, (1<<n))
        gen(0, i, 0);
    printf("%d\n", solve((1<<n)-1, S));

    return 0;
}