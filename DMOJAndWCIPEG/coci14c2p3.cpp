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

const int MAXN = 5010;
int n, k, a[MAXN], curr[MAXN];
map<int, int> id;

int main(){
    scanf("%d%d", &n, &k);
    fori(i, 0, n) {
        scanf("%d", a+i);
        id[a[i]] = i;
    }
    sort(a, a+n);
    fori(i, 0, n) {
        int pos = id[a[i]];
        curr[pos] = i/k;
    }

    //find largest subsequence of n that range [i*k, (i+1)*k-1]
    vector<int> lis(n+1, n+1);
    int ans = 0;
    fori(i, 0, n) {
        auto it = lower_bound(lis.begin(), lis.end(), curr[i]);
        while(*it == curr[i]) it++;
        //printf("%d: %d vs %d\n", it-lis.begin(), *it, curr[i]);
        *it = curr[i];
        //fori(i, 0, n+1) printf("%d, ", lis[i]);cout<<endl;
    }
    fori(i, 0, n) if(lis[i] != n+1) ans++;
    cout << n-ans << endl;

    return 0;
}

