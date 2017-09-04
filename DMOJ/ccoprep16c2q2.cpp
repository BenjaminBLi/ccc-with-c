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

int N, arr[100010], memo[32];

int main(){
    scanf("%d", &N);
    int c;
    fori(i, 1, N+1) scanf("%d", arr+i);
    int ans = 0;
    fori(i, 1, N+1){
        int v = arr[i];
        int bval = 0;
        fori(j, 0, 32)
            if(v & (1<<j)) bval = max(bval, ++memo[j]);

        fori(j, 0, 32) if(v & (1<<j)) memo[j] = bval;
        ans = max(ans, bval);
    }
    cout << ans << endl;
    return 0;
}