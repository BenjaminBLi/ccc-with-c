#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
unordered_map<ll, ii> memo;
int N, M;

ll hsh(ii a){
    ll ret = 1LL*a.first*((int)1e9)+1LL*a.second;
    return ret;
}

ii solve(int n, int m){
    if(n < m){
        int tmp = n;
        n = m;
        m = tmp;
    }
    ii id = ii(n, m);
    ll fin = hsh(id);
    if(n == 0 || m == 0) return ii(0, 0);
    if(memo.count(fin)) return memo[fin];
    ii ret = ii((int)1e9, 0);
    if (n < 2 * m) {
        if (m % 2 == 0) {
            //printf("SOLVING: %d %d\n", n-m/2, m);
            ii curr = solve(n - m / 2, m);
            ret.first = min(ret.first, curr.first + 1);
            ret.second = max(ret.second, curr.second + 1);
        }
        if (n % 2 == 0) {
            ii curr = solve(m - (n / 2), n);
            ret.first = min(ret.first, curr.first + 1);
            ret.second = max(ret.second, curr.second + 1);
        }
    }
    if (n == 2 * m) {
        ii curr = solve(0, 0);
        ret.first = min(ret.first, curr.first+1);
        ret.second = max(ret.second, curr.second+1);
        if (m % 2 == 0) {
            curr = solve(n - (m / 2), m);
            ret.first = min(ret.first, curr.first + 1);
            ret.second = max(ret.second, curr.second + 1);
        }
    } else if(n > 2*m){
        int rem = n % (2 * m);
        int whole = n/(2*m);
        ii curr = solve(rem, m);
        ret.first = min(ret.first, curr.first + whole);
        ret.second = max(ret.second, curr.second + whole);
        if (m % 2 == 0) {
            int a = (int) ceil(1.0 * rem / (m / 2));
            int b = whole - 1;
            int c = 2 * m + rem - a * m / 2;
            curr = solve(c, m);
            ret.first = min(ret.first, curr.first + a + b);
            ret.second = max(ret.second, curr.second + a + 4 * b);
        }
    }

    return memo[fin] = ret;
}

int main(){
    scanf("%d %d", &N, &M);
    ii ans = solve(N, M);
    printf("%d %d", ans.first, ans.second);
    return 0;
}
