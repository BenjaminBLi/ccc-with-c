#include "bits/stdc++.h"
#define fori(i, st, en) for(int i = st; i < en; i++)
using namespace std;
typedef pair<int, int> ii;

int N;
ii val[500010];
long long cnt[660][660], memo[660][660];

long long subrectSum(int a, int b, int x, int y){
    if(x < 0 || y < 0) return 0;
    long long tot = memo[x][y];
    if(a > 0) tot -= memo[a-1][y];
    if(b > 0) tot -= memo[x][b-1];
    if(a > 0 && b > 0) tot += memo[a-1][b-1];
    return tot;
}

int main(){
    scanf("%d", &N);
    fori(i, 0, N){
        int a, b;
        scanf("%d %d", &a, &b);
        cnt[a][b]++;
        val[i] = ii(a, b);
    }
    fori(i, 0, 651){
        fori(j, 0, 651){
            memo[i][j] = cnt[i][j];
            if(i>0) memo[i][j] += memo[i-1][j];
            if(j>0) memo[i][j] += memo[i][j-1];
            if(i>0&& j>0) memo[i][j] -= memo[i-1][j-1];
        }
    }

    fori(i, 0, N){
        int x = val[i].first, y = val[i].second;
        //printf("(%d, %d)\n", x, y);
        printf("%lld ", subrectSum(x+1, y+1,650, 650)+1);
        printf("%lld\n", N - subrectSum(0, 0, x-1, y-1) - cnt[0][y]*(x == 650) - cnt[x][0]*(y==650));
    }

    return 0;
}
