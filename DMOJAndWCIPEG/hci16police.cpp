#include <bits/stdc++.h>
#define fori(i, st, en) for(int i = st; i < en; i++)
#define rfori(i, st, en) for(int i = st; i >= en; i--)
#define f first
#define s second
#define pb push_back
#define sqr(x) (x)*(x)
using namespace std;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ii> vii;
typedef double lf;

int N, arr[100010], H, dq[100010], l, r;
ll memo[100010];

//derive f(a, b) from the initial N^2 dp transition state.
lf f(int a, int b){
    return lf(memo[b] - memo[a] + sqr(ll(arr[b+1])) - sqr(ll(arr[a+1]))) / (2 * lf(arr[b+1] - arr[a+1]));
}

int main() {
    scanf("%d %d", &N, &H);
    fori(i, 1, N+1) scanf("%d", arr+i);
    l = r = 0;
    fori(i, 1, N + 1) {
        //pop all invalid elements off of the lont of the deque
        while(l < r && f(dq[l], dq[l+1]) <= arr[i])
            l++;
        //calculate dp
        memo[i] = memo[dq[l]] + H + sqr(1LL*(arr[i] - arr[dq[l]+1]));
        //pop all invalid elements off the back of the deque
        while(l < r && f(dq[r], i) <= f(dq[r-1], dq[r]))
            r--;
        //insert new element
        dq[++r] = i;
    }
    printf("%lld\n", memo[N]);
    return 0;
}
