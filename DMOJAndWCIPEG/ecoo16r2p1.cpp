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

string in;
int N, r[2000010];
char str[4000010];

int main() {
    int T = 10;
    for (; T--;) {
        memset(r, 0, sizeof(r));
        cin >> in;
        int N = in.size();
        fori(i, 0, N) {
            str[(i << 1)] = '\0';
            str[(i << 1) + 1] = in[i];
        }
        int n = N << 1;
        str[n] = '\0';
        n++;
        int p = 0, mx = 0, blen = 0;
        fori(i, 0, n + 1) {
            if (mx > i) r[i] = min(r[(p << 1) - i], mx - i);
            else r[i] = 0;
            while (i >= r[i] && i + r[i] < n && str[i + r[i]] == str[i - r[i]]) r[i]++;
            if (i + r[i] > mx) mx = i + r[i], p = i;
            if((i-r[i] <= 0 || i + r[i] >= n-1) && blen < r[i]) blen = r[i];
        }
        blen <<= 1;
        blen--;
        blen >>= 1;
        cout << N - blen << endl;
    }
    return 0;
}
