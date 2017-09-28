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

int N, arr[100010], H, last;
ll memo[100010];

// memo[j] + H + (arr[i] - arr[j+1]) * (arr[i] - arr[j+1])

int main() {
    scanf("%d %d", &N, &H);
    fill(memo, memo + 1 + N, 1LL << 60);
    memo[0] = 0;
    last = 0;
    fori(i, 1, N + 1) {
        scanf("%d", arr + i);
        fori(j, last, i) {
            ll c = memo[j] + H + (arr[i] - arr[j + 1]) * (arr[i] - arr[j + 1]);
            if (memo[i] >= c) {
                memo[i] = c;
                last = j;
            }
        }
    }
    printf("%lld\n", memo[N]);
    return 0;
}
