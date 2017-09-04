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

int N, tri[110][110], memo[110][110];

int main(){
    scanf("%d", &N);
    fori(i, 1, N+1) fori(j, 1, i+1) scanf("%d", &tri[i][j]);
    rfori(i, N, 1) rfori(j, i, 1){
            memo[i-1][j-1] = max(memo[i-1][j-1], memo[i][j]+tri[i][j]);
            memo[i-1][j] = max(memo[i-1][j], memo[i][j]+tri[i][j]);
        }
    printf("%d\n", memo[1][1]+tri[1][1]);
    return 0;
}
