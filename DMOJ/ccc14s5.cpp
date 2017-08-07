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

int N, dist[2010][2010], memo[2010][2010];
ii coords[2010];

int sDist(ii a, ii b){
    return (a.f-b.f)*(a.f-b.f) + (a.s-b.s)*(a.s-b.s);
}

int solve(int cdist, int curr){
    int best = 0;
    fori(i, 0, N){
        if(curr == i) continue;
        if(dist[curr][i] < cdist){
            int c = 1 + solve(dist[i][curr], i);
            if(c > best){
                best = c;
            }
        }
    }
    return best;
}

int main(){
    scan(N);
    fori(i, 0, N){
        int x, y;
        scan(x); scan(y);
        coords[i] = ii(x, y);
    }
    coords[N] = ii(0, 0);
    N++;
    fori(i, 0, N) fori(j, 0, N) dist[i][j] = dist[j][i] = sDist(coords[i], coords[j]);
    cout << solve(0x3f3f3f, N-1) << endl;

    return 0;
}