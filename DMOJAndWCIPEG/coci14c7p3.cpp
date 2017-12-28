#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < (int) en; i++)
#define rfori(i, st, en) for(int i = st; i >= (int) en; i--)
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii; typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

const int MAXN = 150010, inf = 1000000000;

int n, a[4][MAXN], memo[8][MAXN], nxt[3], pta, ptb, ptc;

int calc(int k, int pt){
    int &curr = memo[pt][k];
    if(curr != -1) return curr;
    if(k == n) return curr = (pt == ptc ? 0 : inf);
    curr = a[pt][k] + calc(k + 1, pt);
    if(pt != ptc) curr = min(curr, a[nxt[pt]][k] + calc(k + 1, nxt[pt]));
    return curr;
 
}

int solve(int p, int q, int r){
    fori(i, 0, 3) fori(j, 0, n) memo[i][j] = -1;
    pta = p, ptb = q, ptc = r;
    nxt[pta] = ptb;
    nxt[ptb] = ptc;
    return a[pta][0] + calc(1, pta);
}

int main(){
    scanf("%d", &n);
    fori(i, 0, 3) fori(j, 0, n) scanf("%d", &a[i][j]);
    printf("%d\n", min(min(min(min(min(solve(0, 1, 2), solve(0, 2, 1)), solve(1, 0, 2)), solve(1, 2, 0)), solve(2, 0, 1)), solve(2, 1, 0)));
}
