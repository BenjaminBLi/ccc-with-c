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
int n, m, rnk[MAXN];

bool ok[MAXN][MAXN];

bool check(int mask){
    fori(i, 0, n) {
        if(!(mask & (1<<i))) continue;
        fori(j, i + 1, n) {
            if(!(mask & (1<<j))) continue;
            if(!ok[i][j]) return false;
        }
    }

    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    fori(i, 0, n+1) fori(j, 0, n+1) ok[i][j] = true;
    fori(i, 0, m){
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        ok[u][v] = ok[v][u] = false;
    }

    int cnt = 0;
    fori(i, 0, 1<<n){
        cnt += check(i);
    }

    cout << cnt << endl;

    return 0;
}