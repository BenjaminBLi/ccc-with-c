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

int n;

int main(){
    ll mx = 0, sum = 0, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &x);
        mx = max(mx, x);
        sum += x;
    }
    if(mx <= sum-mx && sum%2 == 0) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}

