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

const int MAXN = 30;
int n, a[1<<20], sm[1<<20], memo[1<<20];

int solve(int mask){
    if(mask == (1<<n)-1)
        return 0;

    int &ans = memo[mask];
    if(~ans) return ans;

    ans = 1<<30;
    fori(i, 0, n){
        if(mask & (1<<i)) continue;

        int curr = 0;
        int nmask = mask;
        fori(j, 0, 3) nmask |= 1<<((i+j)%n);

        ans = min(ans, sm[nmask] + solve(nmask));
    }
    return ans;
}

int main(){
    memset(memo, -1, sizeof memo);
    scanf("%d", &n);

    fori(i, 0, n) scanf("%d", a+i);
    fori(i, 0, (1<<n))
        fori(j, 0, n){
            if(i & (1<<j)) continue;
            sm[i] += a[j];
        }
    
    cout << solve(0) << endl;
    
    return 0;
}

