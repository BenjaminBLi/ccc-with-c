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

const int MAXN = 1024; 
int x, c, arr[MAXN][MAXN], pre[MAXN][MAXN], curr[MAXN][MAXN];

int main(){
    scanf("%d", &x);
    int m = 1, n = 1;
    scanf("%d%d", &n,  &m);
    fori(i, 0, n) fori(j, 0, m) scanf("%d", &arr[i][j]);
    
    fori(i, 1, x){
        int R, C;

        fori(i, 0, n) fori(j, 0, m) pre[i][j] = arr[i][j];

        scanf("%d%d", &R, &C);

        fori(i, 0, R) fori(j, 0, C) 
            scanf("%d", &curr[i][j]);

        fori(ai, 0, n) fori(aj, 0, m){
            int str = ai*R, stc = aj*C;
            fori(i, 0, R) fori(j, 0, C) {
                arr[str+i][stc+j] = pre[ai][aj]*curr[i][j]; 
            }
        }
        n *= R;
        m *= C;
    }

    int mn = 1<<30, mx = -mn, mxrs = mx, mnrs = 1<<30, mxcs = mx, mncs = 1<<30;
    fori(i, 0, n) fori(j, 0, m){
        mn = min(mn, arr[i][j]);
        mx = max(mx, arr[i][j]);
    }

    fori(i, 0, n){
        int cs = 0;
        fori(j, 0, m) cs += arr[i][j];
        mxrs = max(mxrs, cs);
        mnrs = min(mnrs, cs);
    }

    fori(j, 0, m){
        int cs = 0;
        fori(i, 0, n) cs += arr[i][j];
        mxcs = max(mxcs, cs);
        mncs = min(mncs, cs);
    }

    printf("%d\n%d\n%d\n%d\n%d\n%d\n", mx, mn, mxrs, mnrs, mxcs, mncs);

    return 0;
}

