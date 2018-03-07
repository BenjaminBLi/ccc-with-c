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

const int maxn = 760, mod = 1000000007;
int R, C, k, a[maxn][maxn], ft[maxn*maxn];
ll memo[maxn][maxn];
bool seen[maxn];

//fucking use a bit, ez

int main(){
    scanf("%d%d%d", &R, &C, &k);
    fori(i, 0, R) {
        fori(j, 0, R) {
            scanf("%d", &a[i][j]);
        }
    }


    return 0;
}