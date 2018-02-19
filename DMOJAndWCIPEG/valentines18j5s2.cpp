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

int n, m, d[11], c[11], f[11][11], cnt[11], target[11], curr[11], ans = 0x7fffffff;

inline void reset(){fori(i, 0, n) cnt[i] = 0;}

inline bool valid(){
    fori(i, 0, n) if(cnt[i] > target[i]) return false;
    return true;
}

void solve(int idx){
    if(idx == m){
        reset();
        int cost = 0;
        fori(i, 0, m){
            cost += d[i] * curr[i];
            fori(j, 0, n)
                cnt[j] += f[i][j]*curr[i];
        }
        if(valid()) {
            fori(i, 0, n) cost += c[i] * (target[i]-cnt[i]);
            ans = min(ans, cost);
        }
        return;
    }
    curr[idx] = 1;
    solve(idx+1);
    curr[idx] = 0;
    solve(idx+1);
}

int main(){
    scanf("%d%d", &n, &m);
    fori(i, 0, n) scanf("%d", c+i);
    fori(i, 0, m) {
        scanf("%d", d+i);
        fori(j, 0, n) 
            scanf("%d", &f[i][j]);
    }
    fori(i, 0, n) scanf("%d", target+i);

    solve(0);
    cout << ans << endl;
    return 0;
}

